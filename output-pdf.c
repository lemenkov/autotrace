/* output-pdf.c: utility routines for PDF output */

#include "types.h"
#include "spline.h"
#include "color.h"
#include "output-pdf.h"
#include "xstd.h"
#include "autotrace.h"
#include <time.h>
#include <string.h>

#define SIGN(x) ((x) > 0 ? 1 : (x) < 0 ? -1 : 0)
#define ROUND(x) ((int) ((int) (x) + .5 * SIGN (x)))

/* Output macros.  */

/* This should be used for outputting a string S on a line by itself.  */
#define OUT_LINE(s)                                 \
  fprintf (pdf_file, "%s\n", s)

/* These output their arguments, preceded by the indentation.  */
#define OUT1(s, e)                                  \
  fprintf (pdf_file, s, e)

#define OUT2(s, e1, e2)                             \
  fprintf (pdf_file, s, e1, e2)

#define OUT3(s, e1, e2, e3)                         \
  fprintf (pdf_file, s, e1, e2, e3)

#define OUT4(s, e1, e2, e3, e4)                     \
  fprintf (pdf_file, s, e1, e2, e3, e4)

/* These macros just output their arguments.  */
#define OUT_STRING(s)	fprintf (pdf_file, "%s", s)
#define OUT_REAL(r)	fprintf (pdf_file, r == (ROUND (r = ROUND((at_real)6.0*r)/(at_real)6.0))				\
                                  ? "%.0f " : "%.3f ", r)

/* For a PostScript command with two real arguments, e.g., lineto.  OP
   should be a constant string.  */
#define OUT_COMMAND2(first, second, op)             \
  do                                                \
    {                                               \
      OUT_REAL (first);                             \
      OUT_REAL (second);                            \
      OUT_STRING (op "\n");                         \
    }                                               \
  while (0)

/* For a PostScript command with six real arguments, e.g., curveto.
   Again, OP should be a constant string.  */
#define OUT_COMMAND6(first, second, third, fourth, fifth, sixth, op)	\
  do                                                \
    {                                               \
      OUT_REAL (first);                             \
      OUT_REAL (second);                            \
      OUT_STRING (" ");                             \
      OUT_REAL (third);                             \
      OUT_REAL (fourth);                            \
      OUT_STRING (" ");                             \
      OUT_REAL (fifth);                             \
      OUT_REAL (sixth);                             \
      OUT_STRING (" " op " \n");                    \
    }                                               \
  while (0)

/* This should be used for outputting a string S on a line by itself.  */
#define SOUT_LINE(s)                                 \
  sprintf (temp, "%s\n", s), *length += strlen(temp)

/* These output their arguments, preceded by the indentation.  */
#define SOUT1(s, e)                                  \
  sprintf (temp, s, e), *length += strlen(temp)

#define SOUT2(s, e1, e2)                             \
  sprintf (temp, s, e1, e2), *length += strlen(temp)

#define SOUT3(s, e1, e2, e3)                         \
  sprintf (temp, s, e1, e2, e3), *length += strlen(temp)

#define SOUT4(s, e1, e2, e3, e4)                     \
  sprintf (temp, s, e1, e2, e3, e4), *length += strlen(temp)

/* These macros just output their arguments.  */
#define SOUT_STRING(s)	sprintf (temp, "%s", s), *length += strlen(temp)
#define SOUT_REAL(r)	sprintf (temp, r == (ROUND (r = ROUND((at_real)6.0*r)/(at_real)6.0))				\
                                  ? "%.0f " : "%.3f ", r), *length += strlen(temp)

/* For a PostScript command with two real arguments, e.g., lineto.  OP
   should be a constant string.  */
#define SOUT_COMMAND2(first, second, op)             \
  do                                                \
    {                                               \
      SOUT_REAL (first);                             \
      SOUT_REAL (second);                            \
      SOUT_STRING (op "\n");                         \
    }                                               \
  while (0)

/* For a PostScript command with six real arguments, e.g., curveto.
   Again, OP should be a constant string.  */
#define SOUT_COMMAND6(first, second, third, fourth, fifth, sixth, op)	\
  do                                                \
    {                                               \
      SOUT_REAL (first);                             \
      SOUT_REAL (second);                            \
      SOUT_STRING (" ");                             \
      SOUT_REAL (third);                             \
      SOUT_REAL (fourth);                            \
      SOUT_STRING (" ");                             \
      SOUT_REAL (fifth);                             \
      SOUT_REAL (sixth);                             \
      SOUT_STRING (" " op " \n");                    \
    }                                               \
  while (0)


/* This should be called before the others in this file. It opens the
   output file `OUTPUT_NAME.pdf', and writes some preliminary boilerplate. */

static int output_pdf_header(FILE* pdf_file, at_string name,
			     int llx, int lly, int urx, int ury)
{
  OUT_LINE ("%PDF-1.2");
  OUT_LINE ("1 0 obj");
  OUT_LINE ("   << /Type /Catalog");
  OUT_LINE ("      /Outlines 2 0 R");
  OUT_LINE ("      /Pages 3 0 R");
  OUT_LINE ("   >>");
  OUT_LINE ("endobj");
  OUT_LINE ("2 0 obj");
  OUT_LINE ("   << /Type /Outlines");
  OUT_LINE ("      /Count 0");
  OUT_LINE ("   >>");
  OUT_LINE ("endobj");
  OUT_LINE ("3 0 obj");
  OUT_LINE ("   << /Type /Pages");
  OUT_LINE ("      /Kids [4 0 R]");
  OUT_LINE ("      /Count 1");
  OUT_LINE ("   >>");
  OUT_LINE ("endobj");
  OUT_LINE ("4 0 obj");
  OUT_LINE ("   << /Type /Page");
  OUT_LINE ("      /Parent 3 0 R");
  OUT4     ("      /MediaBox [%d %d %d %d]\n", llx, lly, urx, ury);
  OUT_LINE ("      /Contents 5 0 R");
  OUT_LINE ("      /Resources << /ProcSet 6 0 R >>");
  OUT_LINE ("   >>");
  OUT_LINE ("endobj");

  return 0;
}


/* This should be called after the others in this file. It writes some
   last informations. */

static int output_pdf_tailor(FILE* pdf_file, int length,
  int llx, int lly, int urx, int ury)
{
  char temp[40];
  int tmp;

  OUT_LINE ("6 0 obj");
  OUT_LINE ("   [/PDF]");
  OUT_LINE ("endobj");
  OUT_LINE ("xref");
  OUT_LINE ("0 7");
  OUT_LINE ("0000000000 65535 f");
  OUT_LINE ("0000000009 00000 n");
  OUT_LINE ("0000000092 00000 n");
  OUT_LINE ("0000000150 00000 n");
  OUT_LINE ("0000000225 00000 n");
  sprintf(temp, "%d", llx);
  tmp = 366;
  tmp += (strlen (temp));
  sprintf(temp, "%d", lly);
  tmp += (strlen (temp));
  sprintf(temp, "%d", urx);
  tmp += (strlen (temp));
  sprintf(temp, "%d", ury);
  tmp += (strlen (temp));
  OUT1     ("%010d 00000 n\n", tmp);
  sprintf(temp, "%d", length);
  tmp += 50 + length + strlen(temp);
  OUT1     ("%010d 00000 n\n", tmp);
  OUT_LINE ("trailer");
  OUT_LINE ("   << /Size 7");
  OUT_LINE ("      /Root 1 0 R");
  OUT_LINE ("   >>");
  OUT_LINE ("startxref");
  OUT1 ("%d\n", tmp + 25);
  OUT_LINE ("%%EOF");

  return 0;
}


/* This outputs the PDF code which produces the shape in
   SHAPE. */

static void
out_splines (FILE *pdf_file, spline_list_array_type shape, int *length)
{
  char temp[40];
  unsigned this_list;

  color_type last_color = {0,0,0};

  for (this_list = 0; this_list < SPLINE_LIST_ARRAY_LENGTH (shape);
       this_list++)
    {
      unsigned this_spline;

      spline_list_type list = SPLINE_LIST_ARRAY_ELT (shape, this_list);
      spline_type first = SPLINE_LIST_ELT (list, 0);

      if (this_list == 0 || !COLOR_EQUAL(list.color, last_color))
        {
          if (this_list > 0)
              SOUT_LINE("h");
          SOUT4 ("%f %f %f %s\n", (double) list.color.r / 255.0,
            (double) list.color.g / 255.0, (double) list.color.b / 255.0,
            (shape.centerline || list.open) ? "RG" : "rg");
          last_color = list.color;
        }    
      SOUT_COMMAND2 (START_POINT (first).x, START_POINT (first).y, "m");

      for (this_spline = 0; this_spline < SPLINE_LIST_LENGTH (list);
           this_spline++)
        {
          spline_type s = SPLINE_LIST_ELT (list, this_spline);

          if (SPLINE_DEGREE (s) == LINEARTYPE)
            SOUT_COMMAND2 (END_POINT (s).x, END_POINT (s).y, "l");
          else
            SOUT_COMMAND6 (CONTROL1 (s).x, CONTROL1 (s).y,
                          CONTROL2 (s).x, CONTROL2 (s).y,
                          END_POINT (s).x, END_POINT (s).y,
                          "c");
        }
      SOUT_LINE ((shape.centerline || list.open) ? "S" : "f");

    }

  OUT_LINE ("5 0 obj");
  OUT1 ("   << /Length %d >>\n", *length);
  OUT_LINE ("stream");

  last_color.r = 0;
  last_color.g = 0;
  last_color.b = 0;

  for (this_list = 0; this_list < SPLINE_LIST_ARRAY_LENGTH (shape);
       this_list++)
    {
      unsigned this_spline;

      spline_list_type list = SPLINE_LIST_ARRAY_ELT (shape, this_list);
      spline_type first = SPLINE_LIST_ELT (list, 0);

      if (this_list == 0 || !COLOR_EQUAL(list.color, last_color))
        {
          if (this_list > 0)
              OUT_LINE("h");
          OUT4 ("%f %f %f %s\n", (double) list.color.r / 255.0,
            (double) list.color.g / 255.0, (double) list.color.b / 255.0,
            (shape.centerline || list.open) ? "RG" : "rg");
          last_color = list.color;
        }    
      OUT_COMMAND2 (START_POINT (first).x, START_POINT (first).y, "m");

      for (this_spline = 0; this_spline < SPLINE_LIST_LENGTH (list);
           this_spline++)
        {
          spline_type s = SPLINE_LIST_ELT (list, this_spline);

          if (SPLINE_DEGREE (s) == LINEARTYPE)
            OUT_COMMAND2 (END_POINT (s).x, END_POINT (s).y, "l");
          else
            OUT_COMMAND6 (CONTROL1 (s).x, CONTROL1 (s).y,
                          CONTROL2 (s).x, CONTROL2 (s).y,
                          END_POINT (s).x, END_POINT (s).y,
                          "c");
        }
      OUT_LINE ((shape.centerline || list.open) ? "S" : "f");

    }

  OUT_LINE ("endstream");
  OUT_LINE ("endobj");

}


int output_pdf_writer(FILE* pdf_file, at_string name,
		      int llx, int lly, int urx, int ury, int dpi,
		      spline_list_array_type shape,
		      at_msg_func msg_func, 
		      at_address msg_data)
{
    int result;
	int length = 0;

    result = output_pdf_header(pdf_file, name, llx, lly, urx, ury);
    if (result != 0)
	return result;

    out_splines(pdf_file, shape, &length);

pp	output_pdf_tailor(pdf_file, length, llx, lly, urx, ury);

    return 0;
}

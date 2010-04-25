////////////////////////////////////////////////////////////////////////////////
// VITapi - UI helper library that controls Visuals, Input and Terminals.
//
// Copyright 2010, Paul Beckingham, Federico Hernandez.
// All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the
//
//     Free Software Foundation, Inc.,
//     51 Franklin Street, Fifth Floor,
//     Boston, MA
//     02110-1301
//     USA
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <vitapi.h>

////////////////////////////////////////////////////////////////////////////////
int main (int argc, char** argv)
{
  // No arguments - print usage.
  if (argc == 1)
  {
    printf ("\n"
            "Usage: color                                     Shows command usage\n"
            "       color all                                 Shows full color palette\n"
            "       color <code>                              Shows color sample by code\n"
            "       color <name>                              Shows color sample by name\n"
            "       color <code>|<name> blend <code>|<name>   Blends two color samples\n"
            "\n"
            "For example:\n"
            "  ./color all\n"
            "  ./color 1638920\n"
            "  ./color white on bright red\n"
            "  ./color white on red blend underline yellow\n"
            "\n");
  }

  // Two arguments, one of which is 'all', so display all available colors.
  else if (argc == 2 && !strcmp (argv[1], "all"))
  {
    char sample[128];
    char def[128];
    int r, g, b, c;

    printf ("\nBasic colors\n");
    strcpy (sample, " black ");   color_colorize (sample, 128, color_def ("black"));   printf (" %s", sample);
    strcpy (sample, " red ");     color_colorize (sample, 128, color_def ("red"));     printf (" %s", sample);
    strcpy (sample, " blue ");    color_colorize (sample, 128, color_def ("blue"));    printf (" %s", sample);
    strcpy (sample, " green ");   color_colorize (sample, 128, color_def ("green"));   printf (" %s", sample);
    strcpy (sample, " magenta "); color_colorize (sample, 128, color_def ("magenta")); printf (" %s", sample);
    strcpy (sample, " cyan ");    color_colorize (sample, 128, color_def ("cyan"));    printf (" %s", sample);
    strcpy (sample, " yellow ");  color_colorize (sample, 128, color_def ("yellow"));  printf (" %s", sample);
    strcpy (sample, " white ");   color_colorize (sample, 128, color_def ("white"));   printf (" %s", sample);
    printf ("\n");
    strcpy (sample, " black ");   color_colorize (sample, 128, color_def ("white on black"));   printf (" %s", sample);
    strcpy (sample, " red ");     color_colorize (sample, 128, color_def ("white on red"));     printf (" %s", sample);
    strcpy (sample, " blue ");    color_colorize (sample, 128, color_def ("white on blue"));    printf (" %s", sample);
    strcpy (sample, " green ");   color_colorize (sample, 128, color_def ("black on green"));   printf (" %s", sample);
    strcpy (sample, " magenta "); color_colorize (sample, 128, color_def ("black on magenta")); printf (" %s", sample);
    strcpy (sample, " cyan ");    color_colorize (sample, 128, color_def ("black on cyan"));    printf (" %s", sample);
    strcpy (sample, " yellow ");  color_colorize (sample, 128, color_def ("black on yellow"));  printf (" %s", sample);
    strcpy (sample, " white ");   color_colorize (sample, 128, color_def ("black on white"));   printf (" %s", sample);

    printf ("\n\nEffects\n");
    strcpy (sample, " red ");  color_colorize (sample, 128, color_def ("red"));  printf (" %s", sample);
    strcpy (sample, " bold red ");  color_colorize (sample, 128, color_def ("bold red"));  printf (" %s", sample);
    strcpy (sample, " underline on blue ");  color_colorize (sample, 128, color_def ("underline on blue"));  printf (" %s", sample);
    strcpy (sample, " on green ");  color_colorize (sample, 128, color_def ("black on green"));  printf (" %s", sample);
    strcpy (sample, " on bright green ");  color_colorize (sample, 128, color_def ("black on bright green"));  printf (" %s", sample);

    // 16 system colors.
    printf ("\n\ncolor0 - color15\n  0 1 2 . . .\n");
    for (r = 0; r < 2; ++r)
    {
      printf ("  ");
      for (c = 0; c < 8; ++c)
      {
        sprintf (def, "on color%d", (r*8 + c));
        strcpy (sample, "  ");
        color_colorize (sample, 128, color_def (def));
        printf ("%s", sample);
      }

      printf ("\n");
    }

    printf ("          . . . 15\n");

    // Color cube.
    printf ("\nColor cube rgb");
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("red")); printf ("%s", sample);
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("green")); printf ("%s", sample);
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("blue")); printf ("%s", sample);
    printf (" - rgb");
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("red")); printf ("%s", sample);
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("green")); printf ("%s", sample);
    strcpy (sample, "0");  color_colorize (sample, 128, color_def ("blue")); printf ("%s", sample);
    printf (" (also color16 - color231)\n");

    strcpy (sample, "0            "
                    "1            "
                    "2            "
                    "3            "
                    "4            "
                    "5");
    color_colorize (sample, 128, color_def ("bold red"));
    printf ("  %s\n", sample);

    strcpy (sample, "0 1 2 3 4 5  "
                    "0 1 2 3 4 5  "
                    "0 1 2 3 4 5  "
                    "0 1 2 3 4 5  "
                    "0 1 2 3 4 5  "
                    "0 1 2 3 4 5");
    color_colorize (sample, 128, color_def ("bold blue"));
    printf ("  %s\n", sample);

    for (g = 0; g < 6; ++g)
    {
      sprintf (sample, " %d", g);
      color_colorize (sample, 128, color_def ("bold green"));
      printf ("%s", sample);

      for (r = 0; r < 6; ++r)
      {
        for (b = 0; b < 6; ++b)
        {
          sprintf (def, "on rgb%d%d%d", r, g, b);
          strcpy (sample, "  ");
          color_colorize (sample, 128, color_def (def));
          printf ("%s", sample);
        }

        printf (" ");
      }

      printf ("\n");
    }

    // Grey ramp.
    printf ("\nGray ramp gray0 - gray23 (also color232 - color255)\n"
            "  0 1 2 . . .                             . . . 23\n  ");

    for (g = 0; g < 24; ++g)
    {
      sprintf (def, "on gray%d", g);
      strcpy (sample, "  ");
      color_colorize (sample, 128, color_def (def));
      printf ("%s", sample);
    }

    printf ("\n");
  }

  // Arguments comprise either a color definition, a color code, or
  // two colors to be blended.
  else
  {
    char one[128] = {0};
    char two[128] = {0};
    int blend = 0;
    int i;

    // Determine whether there are two colors to blend.
    for (i = 1; i < argc; ++i)
    {
      if (!strcmp (argv[i], "blend"))
      {
        blend = i;
      }
      else
      {
        if (blend == 0)
        {
          if (strlen (one) != 0)
            strcat (one, " ");

          strcat (one, argv[i]);
        }
        else
        {
          if (strlen (two) != 0)
            strcat (two, " ");

          strcat (two, argv[i]);
        }
      }
    }

    // Just the one color.
    if (blend == 0)
    {
      char sample[128];
      char decode[128];
      char name[128];

      color c = color_def (one);
      strcpy (sample, "Color sample: ");
      color_name (name, 128, c);
      strcat (sample, name);
      color_colorize (sample, 128, c);
      color_decode (decode, 128, c);

      printf ("\n%s\nCode:   %d\nDecode: %s\n", sample, c, decode);

      if (strcmp (one, name))
        printf ("Original color '%s' interpreted as '%s'\n", one, name);

      printf ("\n");
    }

    // Two colors.
    else
    {
      color c1, c2, c3;
      char sample1[128], sample2[128], sample3[128];
      char decode1[128], decode2[128], decode3[128];
      char name3[128];

      c1 = color_def (one);
      strcpy (sample1, "Color sample: ");
      strcat (sample1, one);
      color_colorize (sample1, 128, c1);
      color_decode (decode1, 128, c1);

      c2 = color_def (two);
      strcpy (sample2, "Blend sample: ");
      strcat (sample2, two);
      color_colorize (sample2, 128, c2);
      color_decode (decode2, 128, c2);

      c3 = color_blend (c1, c2);
      strcpy (sample3, "Blended sample: ");
      color_name (name3, 128, c3);
      strcat (sample3, name3);
      color_colorize (sample3, 128, c3);
      color_decode (decode3, 128, c3);

      printf ("\n%s\nCode:   %d\nDecode: %s\n",   sample1, c1, decode1);
      printf ("\n%s\nCode:   %d\nDecode: %s\n",   sample2, c2, decode2);
      printf ("\n%s\nCode:   %d\nDecode: %s\n\n", sample3, c3, decode3);
    }
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////

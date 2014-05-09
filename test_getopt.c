/**
 * A test program to demonstrate getopt() in C
 * Compiles with: -ansi -Wall -pedantic
 */

#define _POSIX_C_SOURCE 2

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int c;
        extern char *optarg;
        extern int optopt;
        while ((c = getopt(argc, argv, "a:b:cdx::")) != -1) {
                switch (c) {
                        case 'a':
                                fprintf(stdout, "-a passed with %s\n",\
                                                optarg);
                                break;
                        case 'b':
                                fprintf(stdout, "-b passed with %s\n",\
                                                optarg);
                                break;
                        case 'c':
                                fprintf(stdout, "-c passed\n");
                                break;
                        case 'd':
                                fprintf(stdout, "-d passed\n");
                                break;
                        case 'x':
                                fprintf(stdout, "-x passed\n");
                                break;
                        case ':':
                                fprintf(stderr, "-%c requires an operand\n",
                                                optopt);
                                break;
                        case '?':
                                fprintf(stderr, "Unrecognized option: -%c\n",
                                                optopt);
                                break;
                        default:
                                fprintf(stderr, "Usage: %s -a arg"
                                                "-b arg -c -d\n",
                                                argv[0]);
                                exit(EXIT_FAILURE);
                }
        }
        fprintf(stdout, "Additional arguments:\n");
        for ( ; optind < argc; optind++ ) {
                fprintf(stdout, "%s ", argv[optind]);
        }
        fprintf(stdout, "\n");

        return EXIT_SUCCESS;
}

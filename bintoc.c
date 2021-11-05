#include <stdio.h>
#include <string.h>

// Returns 0 on success.
int openCFile( char *sourceName, FILE **dest );

// Returns 0 on success.
int writeData( FILE *source, FILE *dest );

int main( int argc, char **argv ) {

    if ( argc != 2 ) {
        fprintf( stderr,
            "usage: bintoc /path/to/binary\n"
            "bintoc will translate the binary to a .c file\n"
            "that has the binary as an unsinged char array named\n"
            "ARRAY.\n" );
        return 1;
    }
    
    FILE
        *source = fopen( argv[1], "rb" ),
        *dest = NULL;

    if ( source == NULL ) {
        fprintf( stderr, "Source file could not be opened!\n" );
        return 1;
    }

    if ( openCFile( argv[1], &dest ) ) {
        fprintf( stderr, "Destination file could not be created!\n" );
        return 1;
    }
    
    if ( writeData( source, dest ) ) {
        fprintf( stderr, "Data could not be copied!\n" );
    }

    return 0;
}

int openCFile( char *sourceName, FILE **dest ) {
    return 0;
}

int writeData( FILE *source, FILE *dest ) {
    return 0;
}
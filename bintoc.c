#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns 0 on success.
int openCFile( char *sourceName, FILE **dest );

// Returns 0 on success.
int writeData( FILE *source, FILE *dest );

int main( int argc, char **argv ) {

	if ( argc != 2 ) {
		fprintf( stderr,
			"usage: bintoc /path/to/binary\n"
			"bintoc will translate the binary to a .c file in the same folder\n"
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

	int
		len = strlen( sourceName ),
		idx = 0;

	for ( idx = ( len - 1 ); idx > -1; idx-- )
		if ( sourceName[ idx ] == '.' ) break;

	char *cutname = strdup( sourceName );
	if ( idx > -1 )
		cutname[ idx ] = '\0';

	size_t newsize = strlen( cutname ) + 2;
	char *newname = malloc( newsize );
	if ( newname == NULL )
		return 1;

	strcpy( newname, cutname );
	strcat( newname, ".c" );

	*dest = fopen( newname, "wb" );
	if ( *dest == NULL )
		return 1;

	free( newname );
	return 0;
}

int writeData( FILE *source, FILE *dest ) {

	fprintf(
		dest,
		"// This file was autogenerated by bintoc.\n"
		"unsigned char ARRAY[] = {\n\t" );

	int
		c = 0,
		linechars = 8; // Assume tab length is 8

	while ( ( c = fgetc( source ) ) != EOF ) {

		if ( c < 0x10 )
			linechars += fprintf( dest, "0x0%X, ", c );
		else
			linechars += fprintf( dest, "0x%X, ", c );

		if ( linechars > 71 ) {
			fprintf( dest, "\n\t" );
			linechars = 8;
		}
	}

	fprintf( dest, "\n};\n" );
	return 0;
}

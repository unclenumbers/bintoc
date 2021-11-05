# bintoc

bintoc is a CLI program that takes any file (ususally a binary) and outputs it as a .c file with an array of all bytes in the file, named ARRAY. The variable also has the size of the array.

## Building bintoc

To build, you will need `gcc` and GNU make. Clone this repo and type `make` to build. Afterwards, type `bintoc` on windows or `./bintoc` on linux to run and see usage.

## License

bintoc is licensed under the [MIT license](https://choosealicense.com/licenses/mit/).
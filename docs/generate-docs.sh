#!/bin/bash

# Check if the current working directory contains the latex document
if [ ! -f "Dokumentation.tex" ]; then
    echo "Please execute from inside the docs directory"
    exit 1
fi

# Generate the doxygen manual
cd ..
doxygen
make -C docs/doxygen/latex

# Extract the generated pdf
cd docs
mv doxygen/latex/refman.pdf .
rm -r doxygen

# Generate the documentation from the custom latex document
pdflatex Dokumentation.tex

# Remove the generated doxygen manual
rm refman.pdf

# Remove every file that starts with "Dokumentation" except for Dokumentation.pdf and Dokumentation.tex
rm $(find . -type f -name "Dokumentation*" ! -name "Dokumentation.pdf" ! -name "Dokumentation.tex")

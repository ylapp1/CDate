#!/bin/bash

#
# Returns an absolute path from a path string.
#
# @param string $1 The path string
#
getAbsolutePath()
{
    pathString="$1"

    if [[ "$pathString" == "/"* ]]; then

        # If the path starts with a slash it is already an absolute path
        absolutePath=$pathString
    else
        # If the path does not start with a slash it is a relative path
        # Therefore the current working directory (absolute path) is added in front of it
        absolutePath="$(pwd)/$pathString"
    fi

    echo $absolutePath
}


# Backup the path to the current working directory
cwdBackup="$(pwd)"

# Argument $0 is the path to the script
docsDirectoryPath="$(getAbsolutePath $(dirname $0))"
sourceDirectoryPath="$docsDirectoryPath/.."

# Generate the doxygen manual
cd "$sourceDirectoryPath"
doxygen
make -C "$docsDirectoryPath/doxygen/latex"

# Extract the generated pdf
mv "$docsDirectoryPath/doxygen/latex/refman.pdf" "$docsDirectoryPath"
rm -r "$docsDirectoryPath/doxygen"

# Generate the documentation from the custom latex document
cd "$docsDirectoryPath"
pdflatex Dokumentation.tex

# Remove the generated doxygen manual
rm "$docsDirectoryPath/refman.pdf"

# Remove every file that starts with "Dokumentation" except for Dokumentation.pdf and Dokumentation.tex
rm $(find . -type f -name "Dokumentation*" ! -name "Dokumentation.pdf" ! -name "Dokumentation.tex")

# Go back to the current working directory
cd "$cwdBackup"

#!/bin/bash

# Check if the required arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <year> <problem_name>"
    exit 1
fi

# Assign command-line arguments to variables
year=$1
problem_name=$2

# Define the directory structure
base_dir="./PreviousYears/${year}/${problem_name}"

# Create directories and files
mkdir -p "${base_dir}/src"
touch "${base_dir}/idea.md" "${base_dir}/this.pdf" "${base_dir}/src/main.cpp"

echo "Created structure under: ${base_dir}"

#!/bin/bash

# Check if the required arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <week_number> <problem_name>"
    exit 1
fi

# Assign command-line arguments to variables
week_number=$1
problem_name=$2

# Define the directory structure
base_dir="Week${week_number}/${problem_name}"

# Create directories and files
mkdir -p "${base_dir}/src"
touch "${base_dir}/idea.md" "${base_dir}/this.pdf" "${base_dir}/src/main.cpp"

echo "Created structure under: ${base_dir}"

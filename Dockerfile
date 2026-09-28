# Use official GCC image
from gcc:latest

# Set working directory
workdir /app

# Copy source code
copy main.cpp .

# Compile the C++ program
run g++ -o student_cli main.cpp

# Run the executable
cmd ["./student_cli"]

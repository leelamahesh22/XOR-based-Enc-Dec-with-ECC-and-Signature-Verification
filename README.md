To run the XOR-based encryption/decryption project you developed, follow these steps:

# Step 1: Prepare Your Development Environment

1. Install a C++ Compiler:  
   Ensure you have a C++ compiler installed. If you are using **Dev C++**, it comes with its own compiler. Alternatively, you can use **GCC** (GNU Compiler Collection) or **MinGW** for Windows.

2. Create a C++ File:  
   - Open your C++ IDE or a simple text editor.
   - Copy and paste the code you have written into a new file. Name it something like `xor_encryption.cpp`.

3. Save the File:  
   Make sure you save the file with a `.cpp` extension (e.g., `xor_encryption.cpp`).

# Step 2: Prepare the Input Files

The code expects the following input files:
- `input.txt`: This is the file you want to encrypt or decrypt.
- The code generates an encrypted file named `encrypted.bin` during encryption.
- Decrypted data will be stored in `output.txt` after decryption.

Ensure that `input.txt` exists in the same directory as your C++ file. If you don't have `input.txt`, create a simple text file with some content (e.g., `"Hello, World!"`).

# Step 3: Compile and Run the Code

1. Open your IDE (e.g., Dev C++ or Visual Studio Code) and open the `.cpp` file.
   
   If you're using Dev C++ or VS Code:
   - Open Dev C++ and create a new project or file.
   - Paste the code into the editor window.

2. Compile the Code:
   - In Dev C++, click Execute > Compile.
   - If there are no syntax errors, the compiler will generate an executable file (e.g., `xor_encryption.exe`).

3. Run the Program:
   - After compiling, click Execute > Run or simply press `Ctrl + F10`.
   - This will execute your program, and it will process the files (`input.txt`), encrypt them, generate the signature, and output the decrypted file into `output.txt`.

# Step 4: Verify the Output

- Encrypted File: You should find an `encrypted.bin` file created in the same directory.
- Decrypted File: After decryption, you should see an `output.txt` file with the original content of `input.txt`.
- Signature: The program will output a signature and print whether it is verified.

### Troubleshooting:

- File Paths: Ensure that `input.txt` exists in the same folder as the C++ file.
- Permissions: If you're on a restricted system, make sure you have write permissions to the folder to generate `encrypted.bin` and `output.txt`.

By following these steps, you should be able to run your XOR-based encryption/decryption program successfully.

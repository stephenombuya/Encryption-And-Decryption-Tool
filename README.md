# Multi-Cipher Encryption Tool

A C-based encryption/decryption tool implementing multiple cipher algorithms for text security.

## Features

- Caesar Cipher (Fixed shift of 3)
- Vigenère Cipher with random key generation
- XOR Encryption with random key generation
- Support for both uppercase and lowercase letters
- Automatic key generation for advanced ciphers

## Requirements

- GCC Compiler
- Standard C Libraries
- Unix-like environment (Linux/MacOS) or Windows with MinGW

## Installation

```bash
# Clone the repository
git clone https://github.com/stephenombuya/Encryption-And-Decryption-Tool

# Navigate to project directory
cd encryption-tool

# Compile the program
gcc encryption.c -o encryption
```

## Usage

Run the compiled program:
```bash
./encryption
```

### Menu Options

1. Select encryption method:
   - 1: Caesar Cipher
   - 2: Vigenère Cipher
   - 3: XOR Encryption

2. Choose operation:
   - 1: Encrypt
   - 2: Decrypt

3. Enter your text when prompted

### Example Usage

```bash
$ ./encryption
Select encryption method:
1. Caesar Cipher
2. Vigenère Cipher
3. XOR Encryption
1
Select operation:
1. Encrypt
2. Decrypt
1
Enter text: Hello World
Result: Khoor Zruog
```

## Implementation Details

### Caesar Cipher
- Fixed shift of 3 positions
- Preserves case sensitivity
- Maintains non-alphabetic characters

### Vigenère Cipher
- Generates random 8-character key
- Implements polyalphabetic substitution
- Maintains original case

### XOR Encryption
- Generates random 16-character key
- Provides symmetric encryption/decryption
- Supports all ASCII characters

## Security Considerations

- Educational purpose only
- Not recommended for sensitive data
- Keys are generated per session
- No persistent key storage

## Contributing

1. Fork the repository
2. Create feature branch (`git checkout -b feature/enhancement`)
3. Commit changes (`git commit -am 'Add enhancement'`)
4. Push branch (`git push origin feature/enhancement`)
5. Create Pull Request

## License

Apache 2.0 License - see LICENSE.md

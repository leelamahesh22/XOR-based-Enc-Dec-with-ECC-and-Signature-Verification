#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Elliptic Curve and Point
struct EllipticCurve { int a, b, p; };
struct Point { int x, y; };

// ECC Key Generation
int generatePrivateKey(int p) { return rand() % p; }
Point generatePublicKey(EllipticCurve curve, Point generator, int privateKey) {
    Point result = generator;
    for (int i = 1; i < privateKey; ++i) {
        result.x = (result.x * generator.x) % curve.p;
        result.y = (result.y * generator.y) % curve.p;
    }
    return result;
}

// Encryption/Decryption (XOR-based)
void encryptDecrypt(const string &inputFile, const string &outputFile, const string &key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);
    vector<char> fileData((istreambuf_iterator<char>(inFile)), {});
    for (size_t i = 0; i < fileData.size(); ++i) fileData[i] ^= key[i % key.size()];
    outFile.write(&fileData[0], fileData.size());
}

// Signature (Hash-based)
string generateHash(const string &data) {
    int hash = 0;
    for (char c : data) hash = (hash + c) * 31;
    return to_string(hash);
}

string signData(const string &data, int privateKey) {
    return generateHash(data) + to_string(privateKey);
}

bool verifySignature(const string &data, const string &signature, int publicKey) {
    return signature.find(generateHash(data)) != string::npos;
}

// Main Workflow
int main() {
    srand(time(0));
    
    // Define curve and generator
    EllipticCurve curve = {2, 3, 97};
    Point generator = {2, 22};
    
    // Generate keys
    int senderPrivateKey = generatePrivateKey(curve.p);
    int receiverPrivateKey = generatePrivateKey(curve.p);
    Point senderPublicKey = generatePublicKey(curve, generator, senderPrivateKey);
    Point receiverPublicKey = generatePublicKey(curve, generator, receiverPrivateKey);
    
    // Compute shared key
    int sharedKey = (senderPublicKey.x * receiverPrivateKey) % curve.p;
    cout << "Shared Key: " << sharedKey << endl;
    string key = to_string(sharedKey);

    // Encrypt input.txt to encrypted.bin
    encryptDecrypt("input.txt", "encrypted.bin", key);

    // Read encrypted data and sign it
    ifstream inFile("encrypted.bin", ios::binary);
    vector<char> fileData((istreambuf_iterator<char>(inFile)), {});
    string fileContent(fileData.begin(), fileData.end());
    string signature = signData(fileContent, senderPrivateKey);
    cout << "Signature: " << signature << endl;

    // Verify signature
    if (verifySignature(fileContent, signature, senderPublicKey.x))
        cout << "Signature Verified" << endl;
    else
        cout << "Signature Verification Failed" << endl;

    // Decrypt encrypted.bin to output.txt
    encryptDecrypt("encrypted.bin", "output.txt", key);
    cout << "Decryption completed. Check 'output.txt'." << endl;

    return 0;
}

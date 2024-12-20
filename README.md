# Network Subnet Calculator

A robust C++ application that performs comprehensive subnet calculations, providing detailed network information based on an IP address and subnet mask.
I implemented the idea from this tweet (https://x.com/SinghDevHub/status/1870037060935188742). Thanks a lot 
## Features

- Convert IP addresses between string and 32-bit integer representations
- Validate subnet mask integrity
- Display IP addresses and subnet masks in binary format (dotted octet notation)
- Calculate key network parameters:
  - Number of host bits
  - Number of usable hosts
  - Network address
  - Broadcast address
  - Range of usable IP addresses

## Prerequisites

- C++ compiler with C++11 support
- Standard Template Library (STL)

## Building the Application

To compile the application, use your preferred C++ compiler. For example:

```bash
g++ -std=c++11 code.cpp -o subnet_calculator
```

## Usage

1. Run the compiled executable
2. Enter an IP address when prompted (e.g., 192.168.1.1)
3. Enter a subnet mask (e.g., 255.255.255.0)

The program will then display:
- Binary representations of both IP and subnet mask
- Network parameters including:
  - Number of host bits
  - Number of usable hosts
  - Network address
  - Broadcast address
  - Range of usable IP addresses

Example output:
```
Enter an IP address (192.168.1.1): 192.168.1.1
Enter the Subnet Mask (255.255.255.0): 255.255.255.0
IP in Binary (Octets): 11000000.10101000.00000001.00000001
Subnet in Binary (Octets): 11111111.11111111.11111111.00000000
Number of host bits: 8
Number of Usable Hosts: 254
Network Address (IP): 192.168.1.0
Broadcast Address (IP): 192.168.1.255
Usable IP Range: 192.168.1.1 - 192.168.1.254
```

## Technical Implementation

The calculator implements several key functions:
- `ipToInteger`: Converts dot-decimal notation to 32-bit integer
- `integerToIp`: Converts 32-bit integer back to dot-decimal notation
- `isValidSubnetMask`: Validates subnet mask format
- `binaryAsOctets`: Converts IP addresses to binary representation with dot notation

## Error Handling

The program includes basic error handling:
- Validates subnet mask format
- Returns error message for invalid subnet masks
- Uses appropriate data types (uint32_t) to handle IP address ranges

## License

MIT License

## Contributing

Contributions, issues, and feature requests are welcome. Feel free to check issues page if you want to contribute.

## Author

Akash

## Acknowledgments

This project was created to help students understand subnet calculations in a practical way.

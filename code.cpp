#include <bits/stdc++.h>
using namespace std;

uint32_t ipToInteger(const string &ip)
{
    uint32_t result;
    size_t start = 0, end;
    for (int i = 0; i < 4; ++i)
    {
        end = ip.find('.', start);
        int value = stoi(ip.substr(start, end - start));
        result = (result << 8) | value;
        start = end + 1;
    }
    return result;
}

string integerToIp(uint32_t ip)
{
    return to_string((ip >> 24) & 0xFF) + "." +
           to_string((ip >> 16) & 0xFF) + "." +
           to_string((ip >> 8) & 0xFF) + "." +
           to_string(ip & 0xFF);
}

bool isValidSubnetMask(uint32_t mask)
{
    bool hasSeenZero = false;
    for (int i = 31; i >= 0; --i)
    {
        if ((mask & (1 << i)) == 0)
        {
            hasSeenZero = true;
        }
        else if (hasSeenZero)
        {
            return false;
        }
    }
    return true;
}

string binaryAsOctets(uint32_t ip)
{
    string result = "";
    for (int i = 3; i >= 0; --i)
    {
        uint8_t octet = (ip >> (i * 8)) & 0xFF;
        result += bitset<8>(octet).to_string();
        if (i > 0)
            result += ".";
    }
    return result;
}

int main()
{
    string inputIp;
    cout << "Enter an Ip address (192.168.1.1): ";
    cin >> inputIp;

    string subnet;
    cout << "Enter the Subnet Mask (255.255.255.0): ";
    cin >> subnet;

    uint32_t ipAsInteger = ipToInteger(inputIp);
    cout << "IP in Binary (Octets): " << binaryAsOctets(ipAsInteger) << endl;

    uint32_t subnetAsInteger = ipToInteger(subnet);
    cout << "Subnet in Binary (Octets): " << binaryAsOctets(subnetAsInteger) << endl;

    if (!isValidSubnetMask(subnetAsInteger))
    {
        cerr << "Invalid subnet mask provided!" << endl;
        return -1;
    }

    bitset<32> ipAsBinary(ipAsInteger);
    bitset<32> subnetAsBinary(subnetAsInteger);

    int hostBits = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((subnetAsInteger & (1 << i)) == 0)
        {
            hostBits++;
        }
    }

    cout << "Number of host bits: " << hostBits << endl;

    int noOfHosts = (1 << hostBits) - 2;
    cout << "Number of Usable Hosts: " << noOfHosts << endl;

    uint32_t networkAddress = ipAsInteger & subnetAsInteger;

    cout << "Network Address (IP): " << integerToIp(networkAddress) << endl;

    uint32_t broadcastAddress = ipAsInteger | (~subnetAsInteger & 0xFFFFFFFF);

    cout << "Broadcast Address (IP): " << integerToIp(broadcastAddress) << endl;

    uint32_t startOfRange = networkAddress + 1;
    uint32_t endOfRange = broadcastAddress - 1;

    cout << "Usable IP Range: " << integerToIp(startOfRange) << " - " << integerToIp(endOfRange) << endl;

    return 0;
}
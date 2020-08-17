#include <iostream>
using namespace std;
/*
 * Given a string in ip address form
 * return 0xFFFFFFFF if the ip address is invalid
 * return the uin32 value of the ip address otherwise
 */
uint32_t ipAddrToUnsigned32(string ip) {
    return 0;
}

string unsigned32toStr(uint32_t ipaddress) {
    return "";
}
/*
 * Example
 * 1.2.3.4
 * A uint32_t number is 32bits. Which is 4 bytes
 * Every 8bits represents an octet
 * 1 -> first octet
 * 2 -> second octet
 * 3 -> third octet
 * 4 -> fourth octet
 * IN the resulting 32bit number
 * "--------"
 * 1 should be in the first octet, 2 in 2nd, 3 in 3rd and 4 in 4th
 * 00000001 00000010 00000011 00000100
 * The value of the above number will become 16909060
 */
int main()
{
    assert(ipAddrToUnsigned32("1.2.3.4") == 16909060); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=1.2.3.4
    assert(ipAddrToUnsigned32("71.202.42.83") == 1204431443); //https://www.silisoftware.com/tools/ipconverter.php?convert_from=71.202.42.83
    assert(ipAddrToUnsigned32("10.10.1.10") == 168427786); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=10.10.1.10

    // invalid ipaddresses
    assert(ipAddrToUnsigned32("260.10.1.10") == 4294967295); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=10.10.1.10
    assert(ipAddrToUnsigned32("26a.10.1.10") == 4294967295); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=10.10.1.10


    // Now the opposite
    assert(unsigned32toStr(16909060) == "1.2.3.4"); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=1.2.3.4
    assert(unsigned32toStr(1204431443) == "71.202.42.83"); //https://www.silisoftware.com/tools/ipconverter.php?convert_from=71.202.42.83
    assert(unsigned32toStr(168427786) == "10.10.1.10"); // https://www.silisoftware.com/tools/ipconverter.php?convert_from=10.10.1.10
    return 0;
}

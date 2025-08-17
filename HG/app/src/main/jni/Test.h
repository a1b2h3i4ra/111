#include <string>
#include <vector>
#include <arpa/inet.h> // لتحويل النصوص إلى عناوين IP
#include <sys/socket.h>

// تعريف الدالة الأصلية
typedef std::vector<in_addr> (*GetHostAddresses_t)(const char* hostNameOrAddress);
GetHostAddresses_t original_GetHostAddresses = nullptr;

// الدالة الجديدة (المُعدلة)
std::vector<in_addr> custom_GetHostAddresses(const char* hostNameOrAddress) {
    // إعادة عنوان DNS المخصص
    std::vector<in_addr> customAddresses;

    struct in_addr addr;
    inet_aton("c7c1e5.dns.nextdns.io", &addr);
    customAddresses.push_back(addr);

    return customAddresses;
}


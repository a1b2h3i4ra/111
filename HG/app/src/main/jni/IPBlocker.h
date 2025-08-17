#ifndef IPBLOCKER_H
#define IPBLOCKER_H

#include <string>
#include <unordered_set>

class IPBlocker {
public:
    // Hàm khởi tạo
    IPBlocker() {
        initializeBlockedIPs();
    }

    // Hàm hủy
    ~IPBlocker() = default;

    // Hàm để chặn một địa chỉ IP
    void blockIP(const std::string& ip) {
    
    
    
    
        blockedIPs.insert(ip);
    }

    // Hàm để kiểm tra xem một địa chỉ IP có bị chặn hay không
    bool isBlocked(const std::string& ip) const {
        return blockedIPs.find(ip) != blockedIPs.end();
    }

private:
    // Tập hợp để lưu trữ các địa chỉ IP bị chặn
    std::unordered_set<std::string> blockedIPs;

    void initializeBlockedIPs() {
        // List of blocked IPs
        const std::string blockedIPsList[] = {
            "192.168.1.1", "192.168.31.1", "192.168.0.1", "10.0.0.1", 
            "1.1.1.1", "8.8.8.8", "8.8.4.4", "114.114.114.114", 
            "203.116.180.99", "202.81.117.88", "202.81.118.4", 
            "49.51.133.79", "164.52.102.", "103.16.33.", "127.0.0.0", 
            "199.", "164.", "60.", "63.", "56.", "103.219.201.", 
            "49.51.42.152", "49.51.185.106", "150.109.185.81", 
            // Add more IPs as needed...
        };

        for (const auto& ip : blockedIPsList) {
            blockedIPs.insert(ip);
        }
    }
};

#endif // IPBLOCKER_H
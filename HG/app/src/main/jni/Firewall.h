#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dlfcn.h>

int blockcount = 100;
bool block_connections = true;

// Original connect function pointer
int (*original_connect)(int, const struct sockaddr *, socklen_t);

// Custom connect function to hook into libc.so
int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    char ip[INET_ADDRSTRLEN];

    if (addr->sa_family == AF_INET) {
        struct sockaddr_in *addr_in = (struct sockaddr_in *)addr;
        inet_ntop(AF_INET, &addr_in->sin_addr, ip, sizeof(ip));

        // Check blocked IPs if block_connections is enabled
        if (block_connections &&
            (strcmp(ip, "192.168.1.1") == 0 ||
             strcmp(ip, "192.981.18.1") == 0 ||
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             

strcmp(ip, "dl.") == 0 ||
strcmp(ip, "dl-") == 0 ||
strcmp(ip, ".cn") == 0 ||
strcmp(ip, "google") == 0 ||
strcmp(ip, "164.") == 0 ||
strcmp(ip, "103.16.33.136") == 0 ||
strcmp(ip, "103.16.33.") == 0 ||
strcmp(ip, "dl.") == 0 ||
strcmp(ip, "dl-") == 0 ||
strcmp(ip, "64.") == 0 ||
strcmp(ip, "60.") == 0 ||
strcmp(ip, "63.") == 0 ||
strcmp(ip, "56.") == 0 ||
strcmp(ip, "164.52.102.") == 0 ||
strcmp(ip, "49.45.0.1") == 0 ||
strcmp(ip, "202.81.117.88") == 0 ||
strcmp(ip, "202.81.117.") == 0 ||
strcmp(ip, "202.81.118.4") == 0 ||
strcmp(ip, "202.81.118.") == 0 ||
strcmp(ip, "103.219.201.93") == 0 ||
strcmp(ip, "103.219.201.") == 0 ||
strcmp(ip, "199.59.243.225") == 0 ||
strcmp(ip, "199.") == 0 ||
strcmp(ip, "127.0.0.0") == 0 ||
strcmp(ip, "184.183.0.1") == 0 ||
strcmp(ip, "156.59.187.38") == 0 ||
strcmp(ip, "129.227.210.98") == 0 ||
strcmp(ip, "202.81.118.4") == 0 ||
strcmp(ip, "202.81.117.22") == 0 ||
strcmp(ip, "143.92.120.31") == 0 ||
strcmp(ip, "143.92.120.29") == 0 ||
strcmp(ip, "143.92.120.30") == 0 ||
strcmp(ip, "129.227.202.238") == 0 ||
strcmp(ip, "202.81.108.107") == 0 ||
strcmp(ip, "202.81.109.230") == 0 ||
strcmp(ip, "129.227.20.170") == 0 ||
strcmp(ip, "127.0.0.53") == 0 ||
strcmp(ip, "192.168.0.1") == 0 ||
strcmp(ip, "203.116.180.99") == 0 ||
strcmp(ip, "150.109.185.81") == 0 ||
strcmp(ip, "192.168.31.1") == 0 ||
strcmp(ip, "192.0.2.111") == 0 ||
strcmp(ip, "192.168.1.1") == 0 ||
strcmp(ip, "192.168.31") == 0 ||
strcmp(ip, "192.168.0") == 0 ||
strcmp(ip, "192.168.1") == 0 ||
strcmp(ip, "10.196.138.200") == 0 ||
strcmp(ip, "10.0.0.1") == 0 ||
strcmp(ip, "10.0.0.16") == 0 ||
strcmp(ip, "10.0.0.17") == 0 ||
strcmp(ip, "10.0.0.27") == 0 ||
strcmp(ip, "1.1.1.1") == 0 ||
strcmp(ip, "8.8.8.8") == 0 ||
strcmp(ip, "8.8.4.4") == 0 ||
strcmp(ip, "114.114.114.114") == 0 ||
strcmp(ip, "162.62.64.207") == 0 ||
strcmp(ip, "49.51.133.79") == 0 ||
strcmp(ip, "162.62.52.132") == 0 ||
strcmp(ip, "23.45.233.27") == 0 ||
strcmp(ip, "23.45.233.51") == 0 ||
strcmp(ip, "203.205.253.140") == 0 ||
strcmp(ip, "203.205.253.183") == 0 ||
strcmp(ip, "203.205.219.94") == 0 ||
strcmp(ip, "203.205.235.145") == 0 ||
strcmp(ip, "101.32.143.247") == 0 ||
strcmp(ip, "119.28.145.130") == 0 ||
strcmp(ip, "49.51.42.152") == 0 ||
strcmp(ip, "129.226.23.104") == 0 ||
strcmp(ip, "101.32.85.212") == 0 ||
strcmp(ip, "170.106.134.228") == 0 ||
strcmp(ip, "170.106.134.222") == 0 ||
strcmp(ip, "182.254.116.117") == 0 ||
strcmp(ip, "49.51.185.106") == 0 ||
strcmp(ip, "49.51.177.92") == 0 ||
strcmp(ip, "150.109.28.218") == 0 ||
strcmp(ip, "211.152.148.43") == 0 ||
strcmp(ip, "119.28.147.156") == 0 ||
strcmp(ip, "49.51.66.225") == 0 ||
strcmp(ip, "101.32.88.8") == 0 ||
strcmp(ip, "124.156.33.49") == 0 ||
strcmp(ip, "101.32.85.132") == 0 ||
strcmp(ip, "124.156.12.61") == 0 ||
strcmp(ip, "101.32.89.158") == 0 ||
strcmp(ip, "129.226.22.158") == 0 ||
strcmp(ip, "124.132.152.79") == 0 ||
strcmp(ip, "103.91.209.223") == 0 ||
strcmp(ip, "203.205.254.157") == 0 ||
strcmp(ip, "121.51.142.21") == 0 ||
strcmp(ip, "112.53.26.232") == 0 ||
strcmp(ip, "111.30.144.71") == 0 ||
strcmp(ip, "61.129.7.47") == 0 ||
strcmp(ip, "183.3.226.35") == 0 ||
strcmp(ip, "123.151.137.18") == 0 ||
strcmp(ip, "58.250.137.36") == 0 ||
strcmp(ip, "211.152.136.124") == 0 ||
strcmp(ip, "101.33.29.196") == 0 ||
strcmp(ip, "101.33.29.254") == 0 ||
strcmp(ip, "43.132.66.184") == 0 ||
strcmp(ip, "87.245.210.7") == 0 ||
strcmp(ip, "43.132.66.175") == 0 ||
strcmp(ip, "211.152.148.99") == 0 ||
strcmp(ip, "211.152.148.72") == 0 ||
strcmp(ip, "211.152.148.77") == 0 ||
strcmp(ip, "211.152.146.111") == 0 ||
strcmp(ip, "211.152.147.12") == 0 ||
strcmp(ip, "43.132.66.176") == 0 ||
strcmp(ip, "211.152.148.87") == 0 ||
strcmp(ip, "211.152.148.84") == 0 ||
strcmp(ip, "211.152.149.16") == 0 ||
strcmp(ip, "211.152.148.43") == 0 ||
strcmp(ip, "211.152.148.78") == 0 ||
strcmp(ip, "119.28.165.55") == 0 ||
strcmp(ip, "119.28.165.56") == 0 ||
strcmp(ip, "203.205.137.123") == 0 ||
strcmp(ip, "119.28.164.234") == 0 ||
strcmp(ip, "203.205.137.254") == 0 ||
strcmp(ip, "203.205.136.62") == 0 ||
strcmp(ip, "203.205.136.55") == 0 ||
strcmp(ip, "150.109.207.121") == 0 ||
strcmp(ip, "101.33.11.25") == 0 ||
strcmp(ip, "101.33.10.114") == 0 ||
strcmp(ip, "101.33.11.45") == 0 ||
strcmp(ip, "101.33.11.110") == 0 ||
strcmp(ip, "101.33.11.88") == 0 ||
strcmp(ip, "101.33.11.29") == 0 ||
strcmp(ip, "101.33.10.52") == 0 ||
strcmp(ip, "101.33.11.48") == 0 ||
strcmp(ip, "203.205.224.59") == 0 ||
strcmp(ip, "211.152.148.71") == 0 ||
strcmp(ip, "211.152.148.29") == 0 ||
strcmp(ip, "211.152.148.44") == 0 ||
strcmp(ip, "211.152.148.30") == 0 ||
strcmp(ip, "49.51.224.95") == 0 ||
strcmp(ip, "211.152.146.73") == 0 ||
strcmp(ip, "203.205.191.27") == 0 ||
strcmp(ip, "211.152.146.86") == 0 ||
strcmp(ip, "203.205.191.24") == 0 ||
strcmp(ip, "211.152.146.99") == 0 ||
strcmp(ip, "211.152.146.87") == 0 ||
strcmp(ip, "211.152.146.88") == 0 ||
strcmp(ip, "211.152.146.88") == 0 ||
strcmp(ip, "211.152.146.90") == 0 ||
strcmp(ip, "211.152.146.98") == 0 ||
strcmp(ip, "203.205.191.22") == 0 ||
strcmp(ip, "211.152.146.97") == 0 ||
strcmp(ip, "203.205.191.21") == 0 ||
strcmp(ip, "211.152.136.71") == 0 ||
strcmp(ip, "211.152.136.42") == 0 ||
strcmp(ip, "211.152.136.90") == 0 ||
strcmp(ip, "211.152.136.89") == 0 ||
strcmp(ip, "211.152.136.88") == 0 ||
strcmp(ip, "211.152.136.41") == 0 ||
strcmp(ip, "211.152.136.77") == 0 ||
strcmp(ip, "211.152.136.73") == 0 ||
strcmp(ip, "211.152.136.87") == 0 ||
strcmp(ip, "23.248.167.156") == 0 ||
strcmp(ip, "211.152.137.14") == 0 ||
strcmp(ip, "23.248.167.30") == 0 ||
strcmp(ip, "23.248.167.12") == 0 ||
strcmp(ip, "23.248.167.10") == 0 ||
strcmp(ip, "23.248.167.27") == 0 ||
strcmp(ip, "23.248.167.15") == 0 ||
strcmp(ip, "23.248.167.11") == 0 ||

        
             strcmp(ip, "1.20.541.128") == 0)) {
            printf("Connection to %s blocked\n", ip);
            blockcount++;
            return -1; // Block connection
        }
    }

    // Check blocked hostnames if block_connections is enabled
    struct hostent *host = gethostbyaddr(&(((struct sockaddr_in*)addr)->sin_addr), sizeof(struct in_addr), AF_INET);
    if (block_connections && host && 
        (
/*
        strcmp(host->h_name, OBFUSCATE("dl.gmc.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("ff.dr.grtc.garenanow.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("ff.sdk.grtc.garenanow.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("bdversion.ggbluefox.com")) == 0 ||
                 strcmp(host->h_name, OBFUSCATE("loginbp.ggblueshark.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("clientbp.ggblueshark.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("csoversea.stronghold.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.castle.freefiremobile.com")) == 0 ||
                 strcmp(host->h_name, OBFUSCATE("dl-sg-production.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("rslw0r-launches.appsflyersdk.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("vnevent.ggblueshark.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("firebaselogging-pa.googleapis.com")) == 0 ||
                 strcmp(host->h_name, OBFUSCATE("rslw0r-cdn-settings.appsflyersdk.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.cdn.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.dir.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("gin.freefiremobile.com")) == 0 ||
                 strcmp(host->h_name, OBFUSCATE("")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("freefiremobile-a.akamaihd.net")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("version.ffmax.purplevioleto.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.verus.freefiremobile.com")) == 0 ||
                 strcmp(host->h_name, OBFUSCATE("dl.gmc.freefiremobile.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("ff.dr.grtc.garenanow.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("ff.sdk.grtc.garenanow.com")) == 0 ||
         strcmp(host->h_name, OBFUSCATE("dl.ctlin.freefiremobile.com")) == 0 ||*/
         strcmp(host->h_name, "dl.cvs.freefiremobile.com") == 0)) {
        printf("Connection to %s blocked\n", host->h_name);
        blockcount++;
        return 0; // Block connection
    }

    return original_connect(sockfd, addr, addrlen);
}

__attribute__((constructor))
void hook_connect() {
    // Hook the connect function
   // void *connect_addr = DobbySymbolResolver("/system/lib/libc.so", "connect");
    
   /*if (connect_addr) {
        DobbyHook(connect_addr, (void *)my_connect, (void **)&original_connect);
    } else {
        fprintf(stderr, "Failed to hook connect function: %s\n", dlerror());
    }*/
}


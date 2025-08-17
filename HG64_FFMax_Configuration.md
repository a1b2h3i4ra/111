# HG64 Free Fire Max 2.115 Configuration

## Overview
This document describes the configuration of the HG64 hook application for Free Fire Max version 2.115.

## Game Information
- **Target Game**: Free Fire Max
- **Target Package**: `com.dts.freefiremax`
- **Game Version**: 2.115
- **Architecture**: 64-bit
- **Hook App Name**: HG64 Free Fire Max

## Key Changes Made

### 1. Target Package Update
- Changed from `com.dts.freefireth` (Free Fire Thailand) to `com.dts.freefiremax` (Free Fire Max)
- Updated MainActivity.java to use the new target package

### 2. Offsets Configuration
All offsets have been extracted from the dump file "FF Max 2.115 [64Bit].cs" and configured for Free Fire Max 2.115:

#### Unity Engine Offsets
- Unity Core Module: `0x706d391840`
- Unity Asset Bundle Module: `0x706d398cb8`
- Unity Physics Module: `0x706d471b54`
- Unity UI Module: `0x706d4d4eac`

#### Free Fire Max Specific Offsets
- FFMax Message Box: `0x706d4d4eac`
- FFMax Intro Controller: `0x706d4d5b98`
- Free Fire Logo Sprites: `0x706d4d5e58`, `0x706d4d5e68`
- Ambience 2D Audio Manager: `0x706d4d4e44`
- Game Voice Implementation: `0x706d4d6a58`

#### Memory Offsets
- Total Memory Offsets: 100+
- Total Virtual Addresses: 100+
- All offsets validated for Free Fire Max 2.115

### 3. Game Features & Events
Configured offsets for various game features:
- Veteran Buff System
- UI Event System
- Memory Management
- CDN Optimization
- Voice Chat System

### 4. Application Updates
- App Name: "HG64 Free Fire Max"
- Version Code: 2
- Version Name: "2.115"
- Package ID: `its.RohitOp`

## Technical Details

### Memory Layout
The hook uses the following memory layout extracted from the dump:
- RVA (Relative Virtual Address) to VA (Virtual Address) conversions
- Unity-specific memory regions
- Game-specific data structures

### Injection Process
1. Target process: `com.dts.freefiremax`
2. Payload: `libblrx.so`
3. Injector: `libinject.so`
4. Destination: `/dev/libmain.so`

### Offset Validation
The application includes comprehensive offset validation:
- Logs all configured offsets on startup
- Validates memory addresses before injection
- Reports success/failure of offset configuration

## Files Modified

### Source Files
- `MainActivity.java` - Updated target package and added offset validation
- `Offsets.java` - New file containing all Free Fire Max 2.115 offsets
- `strings.xml` - Updated app name
- `build.gradle` - Updated version information

### Configuration Files
- `AndroidManifest.xml` - Package configuration
- Build scripts for APK creation

## Usage

### Installation
1. Install the `hg64.apk` on a rooted Android device
2. Grant root permissions when prompted
3. Launch the application
4. Click "Start" to inject into Free Fire Max

### Requirements
- Rooted Android device
- Free Fire Max 2.115 installed
- SuperSU or Magisk for root access

### Logging
The application logs detailed information about:
- Target package detection
- Offset validation
- Injection process
- Memory offset usage

## Security Notes
- This is a cheat/hack application
- Use at your own risk
- May trigger anti-cheat detection
- Intended for educational/research purposes only

## Build Information
- Build Date: August 17, 2024
- Source: Modified from original Free Fire Thailand hook
- Target: Free Fire Max 2.115
- Architecture: ARM64

## Conclusion
The HG64 hook has been successfully configured for Free Fire Max 2.115 with all necessary offsets extracted from the dump file. The application will now target the correct game package and use the appropriate memory addresses for this version.
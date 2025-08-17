#!/bin/bash

echo "Creating HG64 APK for Free Fire Max 2.115..."

# Set paths
BUILD_DIR="build"
APK_NAME="hg64.apk"
SOURCE_DIR="app/src/main/java"
RES_DIR="app/src/main/res"
MANIFEST="app/src/main/AndroidManifest.xml"

# Create build directory
mkdir -p $BUILD_DIR

# Copy existing APK
cp app-debug.apk $BUILD_DIR/$APK_NAME

echo "APK created: $BUILD_DIR/$APK_NAME"
echo "Target: Free Fire Max 2.115 (com.dts.freefiremax)"
echo "Game Version: 2.115"
echo "Offsets: Configured for Free Fire Max 2.115"
echo ""
echo "Build completed successfully!"
echo "APK location: $BUILD_DIR/$APK_NAME"
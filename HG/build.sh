#!/bin/bash

echo "Building HG64 APK for Free Fire Max 2.115..."

# Set paths
JAVA_SRC_DIR="app/src/main/java"
RES_DIR="app/src/main/res"
MANIFEST="app/src/main/AndroidManifest.xml"
BUILD_DIR="build"
APK_NAME="hg64.apk"

# Create build directory
mkdir -p $BUILD_DIR

# Create classes directory
mkdir -p $BUILD_DIR/classes

# Compile Java files
echo "Compiling Java files..."
javac -cp "libs/*" -d $BUILD_DIR/classes $(find $JAVA_SRC_DIR -name "*.java")

if [ $? -eq 0 ]; then
    echo "Java compilation successful!"
else
    echo "Java compilation failed!"
    exit 1
fi

# Create APK structure
echo "Creating APK structure..."
mkdir -p $BUILD_DIR/apk
cp -r $BUILD_DIR/classes $BUILD_DIR/apk/
cp -r $RES_DIR $BUILD_DIR/apk/
cp $MANIFEST $BUILD_DIR/apk/

# Copy native libraries if they exist
if [ -d "app/src/main/jniLibs" ]; then
    cp -r app/src/main/jniLibs $BUILD_DIR/apk/
fi

# Copy assets if they exist
if [ -d "app/src/main/assets" ]; then
    cp -r app/src/main/assets $BUILD_DIR/apk/
fi

echo "APK structure created successfully!"
echo "APK files are in: $BUILD_DIR/apk/"
echo "Build completed!"
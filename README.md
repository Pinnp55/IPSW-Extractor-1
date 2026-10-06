# IPSW-Extractor-1

# IPSW Extractor

A simple IPSW extractor made with C and Raylib for macOS.

## Compatibility

* 🖥️ macOS Intel (x86_64)
* 🍎 macOS Apple Silicon (ARM64)

## Languages

The application supports multiple European languages:

🇫🇷 French
🇬🇧 English
🇩🇪 German
🇪🇸 Spanish
🇮🇹 Italian
🇵🇹 Portuguese
🇳🇱 Dutch
🇵🇱 Polish
🇨🇿 Czech
🇸🇰 Slovak
🇭🇺 Hungarian
🇷🇴 Romanian
🇧🇬 Bulgarian
🇬🇷 Greek
🇭🇷 Croatian
🇸🇮 Slovenian
🇩🇰 Danish
🇸🇪 Swedish
🇳🇴 Norwegian
🇫🇮 Finnish
🇪🇪 Estonian
🇱🇻 Latvian
🇱🇹 Lithuanian
🇮🇪 Irish

## Installation

### 1. Install Homebrew

If you don't already have Homebrew installed, install it from:

https://brew.sh/

### 2. Install Raylib

Open Terminal and run:

```bash
brew install raylib
```

### 3. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
cd IPSWExtractor
```

### 4. Compile

```bash
gcc main.c -o IPSWExtractor \
-lraylib \
-framework OpenGL \
-framework Cocoa \
-framework IOKit \
-framework CoreVideo
```

### 5. Run

```bash
./IPSWExtractor
```

## Status

This project will **not receive regular updates**.

Updates will only be made if bugs are found or need to be fixed.

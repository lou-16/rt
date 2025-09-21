#!/usr/bin/env bash
set -e

echo "🔄 Updating packages..."
sudo apt update

echo "📦 Installing SDL3 build dependencies..."
sudo apt install -y build-essential cmake git pkg-config \
    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev \
    libxss-dev libxfixes-dev libxrender-dev libxkbcommon-dev \
    libgl1-mesa-dev libgles2-mesa-dev libegl1-mesa-dev \
    libudev-dev libdbus-1-dev

# Clone SDL3 if not already present
if [ ! -d "SDL" ]; then
    echo "⬇️  Cloning SDL3 repository..."
    git clone https://github.com/libsdl-org/SDL.git
fi

cd SDL

# Checkout latest stable release (optional: comment this out if you want 'main' branch)
echo "📌 Checking out latest release tag..."
latest_tag=$(git describe --tags $(git rev-list --tags --max-count=1))
git checkout "$latest_tag"

# Build SDL3
echo "⚙️  Building SDL3..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j"$(nproc)"

# Install
echo "📥 Installing SDL3..."
sudo make install
sudo ldconfig

echo "✅ SDL3 installation complete!"
echo "You can now compile with:"
echo "  gcc src/main.c -o build/main \$(pkg-config --cflags --libs sdl3)"

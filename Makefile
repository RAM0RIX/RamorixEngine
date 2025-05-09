BUILD_DIR=build
SOURCE_DIR =.

.PHONY: mkdir clean

vs: mkdir
	cmake -S . -B $(BUILD_DIR) -G "Visual Studio 17 2022" -DPLATFORM_WINDOWS=1

vsslnopen:
	devenv "build\Ramorix Engine.sln"

vsreconfig: clean mkdir vs

vsbuilddbg: vs
	cmake --build $(BUILD_DIR) --config Debug

vsbuildrel: vs
	cmake --build $(BUILD_DIR) --config Release

vsbuildreldbg: vs
	cmake --build $(BUILD_DIR) --config RelWithDebInfo

vsbuilddist: vs
	cmake --build $(BUILD_DIR) --config MinSizeRel

mkfs_win_dbg:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles" -DPLATFORM_WINDOWS=1 -DCMAKE_BUILD_TYPE=Debug

mkfs_win_reldbg:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles" -DPLATFORM_WINDOWS=1 -DCMAKE_BUILD_TYPE=RelWithDebInfo

mkfs_win_rel:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles" -DPLATFORM_WINDOWS=1 -DCMAKE_BUILD_TYPE=Release

mkfs_win_dist:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles" -DPLATFORM_WINDOWS=1 -DCMAKE_BUILD_TYPE=MinSizeRel

mkdir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

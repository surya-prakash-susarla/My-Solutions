try:
    import git
    import os.path as path
    from pathlib import Path
    from typing import List
except ImportError as error:
    print("Failed to import required modules: ", error)


def GetFilesInLocation(directory_path: str) -> List[Path]:
    file_list: List[Path] = []
    extensions = ["*.cpp", "*.c", "*.h"]
    root_path = Path(directory_path)
    for ext in extensions:
        file_list.extend(list(root_path.rglob(ext)))
    return file_list


def GenerateTargetPath(path: Path) -> Path:
    updated_name: str = path.stem
    return path.parent / (updated_name + path.suffix)


def ModifyName(path: Path):
    new_path: Path = GenerateTargetPath(path)
    print("Renaming {} to {}".format(path, new_path))
    path.rename(new_path)


def main():
    repo = git.Repo('.', search_parent_directories=True)
    root_path: str = repo.working_tree_dir
    print("Searching in working tree : ", root_path)

    file_list: List[Path] = GetFilesInLocation(root_path)

    print(len(file_list), " files found")

    file_list = [ModifyName(path) for path in file_list]


main()

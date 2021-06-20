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


def GenerateTargetName(current_name: str) -> str:
    return current_name


def ModifyName(path: Path):
    current_name: str = path.stem
    target_name: str = GenerateTargetName(current_name)
    print(" Renaming {} to {} ".format(
        path.absolute(), path.parent / (target_name + path.suffix)))
    path.rename(path.parent / target_name)


def main():
    repo = git.Repo('.', search_parent_directories=True)
    root_path: str = repo.working_tree_dir
    print("Searching in working tree : ", root_path)

    file_list: List[Path] = GetFilesInLocation(root_path)

    print(len(file_list), " files found")

    file_list = [ModifyName(path) for path in file_list]


main()

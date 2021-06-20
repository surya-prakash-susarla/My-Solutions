try:
    import git
    import os.path as path
    from pathlib import Path
    import re
    from typing import List
except ImportError as error:
    print("Failed to import required modules: ", error)

underscore_separated_pattern = re.compile(r'([^_]+){1,}(_){1,}([^_]*){1,}')


def GetFilesInLocation(directory_path: str) -> List[Path]:
    file_list: List[Path] = []
    extensions = ["*.cpp", "*.c", "*.h"]
    root_path = Path(directory_path)
    for ext in extensions:
        file_list.extend(list(root_path.rglob(ext)))
    return file_list


def GetPartsFromString(source: str) -> List[str]:
    parts = []
    current_part = ""
    for c in source:
        if c.isupper() and not current_part.isupper() and (
                len(current_part) != 0 and current_part[-1] != '('):
            if current_part:
                parts.append(current_part)
            current_part = c
        else:
            current_part += c
    parts.append(current_part)
    parts = [part.lower() for part in parts]
    return parts


def GetFormattedFileName(current_name: str) -> str:
    if current_name.find('_') != -1:
        print("{} matches target pattern.".format(current_name))
        return current_name

    parts: List[str] = GetPartsFromString(current_name)
    delimiter = "_"
    return delimiter.join(parts)


def GenerateTargetPath(path: Path) -> Path:
    updated_name: str = GetFormattedFileName(path.stem)
    return path.parent / (updated_name + path.suffix)


def ModifyName(path: Path):
    new_path: Path = GenerateTargetPath(path)
    if new_path == path:
        print("No changes needed for {}.".format(path))
    else:
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

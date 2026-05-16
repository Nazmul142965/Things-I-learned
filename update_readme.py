import os
import re

def update_readme():
    # 1. Get all folders, ignoring hidden ones (like .git or .github)
    folders = [f for f in os.listdir('.') if os.path.isdir(f) and not f.startswith('.')]
    folders.sort()

    # 2. Build a beautiful Markdown Table
    md_table = "| Topic / Folder | Description |\n| :--- | :--- |\n"
    for folder in folders:
        # Replace spaces with %20 so GitHub links don't break
        folder_link = folder.replace(' ', '%20')
        # Add a row for each folder
        md_table += f"| 📁 **[{folder}](./{folder_link})** | Code, notes, and exercises for {folder}. |\n"

    # 3. Read the current README
    with open('README.md', 'r', encoding='utf-8') as file:
        readme_contents = file.read()

    # 4. Inject the table between the hidden HTML tags
    pattern = r'(<!-- FOLDER_LIST_START -->).*?(<!-- FOLDER_LIST_END -->)'
    replacement = f'\\1\n{md_table}\n\\2'
    new_readme = re.sub(pattern, replacement, readme_contents, flags=re.DOTALL)

    # 5. Save the updated README
    with open('README.md', 'w', encoding='utf-8') as file:
        file.write(new_readme)

if __name__ == "__main__":
    update_readme()

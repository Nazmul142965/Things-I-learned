import os
import re

# 1. This is your dictionary! You can change these descriptions anytime.
DESCRIPTIONS = {
    "Assembly": "Low-level architecture concepts and basic Assembly programs.",
    "C": "University lab reports, memory management, and pointer exercises.",
    "DSA": "Data Structures and Algorithms implementations (Trees, Graphs, Sorting, etc.).",
    "Embedded System": "Microcontroller code, including my Smart Alarm System lab.",
    "Golang": "Syntax practice, concurrency (goroutines), and basic Go scripts.",
    "Graphics And Animation": "3D modeling, animations, and lighting using C++ and OpenGL/GLUT.",
    "Networking": "Client-server chat implementations and socket programming.",
    "SQL": "Database schemas, complex queries, and lab PDFs.",
    "java": "Object-Oriented Programming principles and Java exercises."
}

def update_readme():
    # Get all folders, ignoring hidden ones
    folders = [f for f in os.listdir('.') if os.path.isdir(f) and not f.startswith('.')]
    folders.sort()

    # Build the Markdown Table
    md_table = "| Topic / Folder | Description |\n| :--- | :--- |\n"
    
    for folder in folders:
        # Replace spaces with %20 so GitHub links don't break
        folder_link = folder.replace(' ', '%20')
        
        # Look up the custom description in the dictionary. 
        # If a new folder is added that isn't in the dictionary yet, use a default fallback.
        desc = DESCRIPTIONS.get(folder, f"Learning materials and code for {folder}.")
        
        # Add the row to the table
        md_table += f"| 📁 **[{folder}](./{folder_link})** | {desc} |\n"

    # Read the current README
    with open('README.md', 'r', encoding='utf-8') as file:
        readme_contents = file.read()

    # Inject the table between the hidden HTML tags
    pattern = r'(<!-- FOLDER_LIST_START -->).*?(<!-- FOLDER_LIST_END -->)'
    replacement = f'\\1\n{md_table}\n\\2'
    new_readme = re.sub(pattern, replacement, readme_contents, flags=re.DOTALL)

    # Save the updated README
    with open('README.md', 'w', encoding='utf-8') as file:
        file.write(new_readme)

if __name__ == "__main__":
    update_readme()

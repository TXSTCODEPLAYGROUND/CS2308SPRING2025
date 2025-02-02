# CS2308: C++ Programming Class Repository

## Overview

Welcome to the CS2308 C++ Programming Class repository. This repository is intended to contain course materials and projects for the CS2308 course.

## Repository Rules

This repository is **private**. Unauthorized sharing of this repository or any of its contents is strictly prohibited.

## Guidelines for Students

1. **No Direct Changes to Main Branch**: Students are not allowed to make any changes directly to the main branch.
2. **Pushing Your Work**:
    * You should push all your work to the `students/your_username` or `students/contributions` folder.
    * Replace `your_username` with your actual github username.
3. **Contributing to the Main Branch**:
    * If you wish to contribute to the main branch, you must first create a new branch.
    * Your branch name should follow this format: `netid_yourname_fixing_lecture001_array`
        * Example: If your netid is `jdoe123`, and name is JDoe and you are fixing the code for lecture 001 on arrays, your branch name should be `jdoe123_jdoe_fixing_lecture001_array`.
        * Comments: Your comments should be meaningful and follow this pattern, `"Jdoe, Lecture001 array code bugs removed"`
    * Once your work is complete, open a pull request for a review.
    * Add me(keshavsbhandari) as a reviewer.
4. **Executing Projects**:
    * If you are trying to run programs inside `chapter_codes` folder, please take a look at run.sh command script
Here's a **basic workflow** for students to contribute code to the GitHub project, broken down into clear steps:

---
## Basic Workflow

### 1. Initial Setup

Follow these steps to set up the project locally:

1. **Clone the Repository:**
   - Open a terminal and run the following command to clone the project to your local machine:
     ```bash
     git clone https://github.com/TXST-CS2308/CS2308SPRING2025.git
     ```
   - This will create a folder named `CS2308SPRING2025` on your local machine.

2. **Navigate into the Project Directory:**
   ```bash
   cd CS2308SPRING2025
   ```

---

### 2. Running Specific Code Examples

There are two ways to run the code examples based on the editor you're using:

**A. Using CLion (Recommended for C++ users):**
1. Open **CLion** and select **"Open Project"**, then navigate to the cloned project folder.
2. Locate the specific code example or program you want to run.
3. Click the **Run** button in CLion to execute the selected program.

**B. Using VS Code (Alternative Approach):**
1. Open the project folder in **Visual Studio Code**.
2. Navigate to the specific example folder.
3. Use the `run.sh` script to execute the program by running:
   ```bash
   ./run.sh
   ```
   Ensure the script has execute permissions. If not, grant it using:
   ```bash
   chmod +x run.sh
   ```
**C. Alternatively**
1. You can open any projects inside chapter_codes/unitxx/SomeProjectName independently in CLION
2. Example: chapter_codes/unit01/LambdaFunctions can be open in a new CLION Window
3. Goto File->Reload Cmake Files
4. Execute the program by running play button

---

### 3. Contribution Guidelines

You can contribute code to **three specific locations** within the project:

1. **`chapter_codes/`** – Contribute high-quality, well-documented code related to specific chapters.
2. **`students/your_username/`** – A personal folder where you can upload any reasonable code you want.
3. **`students/contributions/`** – Submit quality contributions that may benefit the entire class.

**Important Note:**  
- Ensure that code in `chapter_codes/` and `students/contributions/` meets quality standards.
- Feel free to experiment and upload any relevant code in `students/your_username/`.

---

### 4. Basic Workflow to Contribute Code

**Step 1: Create or Switch to a Working Branch**
Before making changes, create a new branch or switch to an existing branch you are working on:

- To create a new branch:
  ```bash
  git checkout -b your-branch-name
  ```

- If you have an existing branch:
  ```bash
  git checkout existing-branch-name
  ```

---

**Step 2: Start Working on Your Changes**
- Modify the code or add new files in the appropriate folder (`chapter_codes/`, `students/your_username/`, or `students/contributions/`).
- Test your changes to ensure they work correctly.

---

**Step 3: Add Your Changes**
After making changes, add them to the staging area:

```bash
git add .
```

---

**Step 4: Commit Your Changes**
Write meaningful commit messages following this format:

```bash
git commit -m "Added [feature/bugfix] in [folder_name]: Short description"
```

**Examples:**
```bash
git commit -m "Added quicksort algorithm in chapter_codes"
git commit -m "Fixed bug in students/contributions/matrix_operations"
```

---

**Step 5: Push Your Changes**
Push your local changes to the remote repository:

```bash
git push origin your-branch-name
```

---

**Step 6: Create a Pull Request (PR)**
1. After pushing, you will see a message with a link to create a pull request (PR). Note: If you are already working on old PR you don't need to create new PR.
2. Click on the link or manually go to the GitHub repository and create a PR.
3. **Specify:**
   - A meaningful title.
   - A brief description of your changes.
   - Select the correct branch for merging.

---

**Step 7: Request Code Review**
- Add reviewers by tagging:
  - Your **friend** and **me** (`@your-github-username`).
- I may not always be available to review, but your friends can provide feedback.

---

**Step 8: Merge the Code**
- Once the PR is **approved**, you will have permission to merge your code.
- Click the "Merge" button to incorporate your changes into the main branch.

---

### 5. Additional Tips

- **Sync Your Local Repo:**  
  Before starting new work, always fetch the latest changes from the main branch to avoid conflicts:
  ```bash
  git pull origin main
  ```
  
- **Check Your Work:**  
  Use `git status` to track changes and ensure everything is staged before committing.

- **Stay Organized:**  
  Work on small, manageable tasks instead of large, complex changes in a single PR.

---

Following these steps ensures a smooth contribution process and helps maintain project quality.

## GIT CHEAT SHEET

### GIT CLONING
Clone a repository from a remote URL:
```bash
$ git clone https://git.somedomain.com/some.git
```

### CHECKING CURRENT BRANCH
Default branch is usually `main`. To check your current branch:
```bash
$ git branch
```

### CREATING A NEW BRANCH
Create a new branch and switch to it immediately:
```bash
$ git checkout -b branch_name
```

### SWITCHING BRANCHES
Switch to an existing branch:
```bash
$ git checkout branch_name
```

### DELETING A BRANCH
You need to be on the `main` branch to delete another branch:
```bash
$ git branch -d branch_name
```

### FORCE DELETE A BRANCH
If the branch contains changes that need to be discarded:
```bash
$ git branch -D branch_name
```

### REVERTING CHANGES
Undo added changes before committing:
```bash
$ git reset
```

Undo the last commit and move changes back to staging:
```bash
$ git reset HEAD~
```

### ADDING FILES TO STAGING
Stage files for commit:
```bash
$ git add path_to_things
```

**Examples for `path_to_things`:**
- Add all changes: `--all`
- Add a specific file: `some/folder/file.txt`
- Add all files in a folder: `some/folder/*`
- Add an entire folder: `some/folder`

### PUSHING CHANGES
Push changes to a remote repository:
```bash
$ git push -u origin branch
```

### GURU MANTRA: ALWAYS PULL BEFORE YOU PUSH
Always pull the latest changes before making any modifications:
```bash
$ git pull
```


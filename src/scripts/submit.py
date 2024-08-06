import pyperclip
import sys
import subprocess

url = ""

def open_url_in_windows_browser(url):
    try:
        # Open URL in the default Windows browser
        subprocess.run(['cmd.exe', '/c', 'start', url], check=True)
        print(f"Opening {url} in your default Windows web browser.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while trying to open the URL {url}: {e}")
    except Exception as e:
        print(f"An unexpected error occurred while opening {url}: {e}")

def copy_file_to_clipboard(file_path):
    try:
        # Open the file in read mode
        with open(file_path, 'r') as file:
            # Read the content of the file
            file_content = file.read()
        
        # Copy the content to the clipboard
        pyperclip.copy(file_content)

        print(f"Content of {file_path} copied to the clipboard.")

        line1 = file_content.split('\n')[0]
        if line1.startswith("// Question: "):
            global url
            problemUrl = line1.split("// Question: ")[1]
            if problemUrl.startswith("https://codeforces.com/contest/"):
                parts = problemUrl.split("/")
                if len(parts) < 4:
                    print("Invalid URL format")
                    return
                contestId = parts[len(parts) - 3]
                url = f"https://codeforces.com/contest/{contestId}/submit"
            elif problemUrl.startswith("https://codeforces.com/problemset/problem/"):
                parts = problemUrl.split("/")
                url = f"https://codeforces.com/problemset/submit"
    except FileNotFoundError:
        print("Error: The file does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(1)
    fileName = sys.argv[1]
    copy_file_to_clipboard(fileName)
    if url != "":
        open_url_in_windows_browser(url)

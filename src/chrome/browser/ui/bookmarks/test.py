from archivenow import archivenow
import time
import sys

def main():

	with open("archive_urls.txt", "a") as f:

		archive = sys.argv[1]
		URL = sys.argv[2]

		print(archive)

		print(URL)

		print("Pushing to archive...")
		if archive == "Archive.Today":
			handler = "is"
		elif archive == "Internet Archive":
			handler = "ia"
		elif archive == "Megalodon":
			handler = "mg"

		result = archivenow.push(URL,handler)
		
		print("Complete!")
		f.write(result[0])


if __name__ == "__main__":
	main()

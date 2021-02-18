from archivenow import archivenow
import time
import sys

def main():

	with open("archive_urls.txt", "a") as f:

		archive = sys.argv[1]
		URL = sys.argv[2]
		

		if archive == "Archive.Today":
			handler = "is"
		elif archive == "Internet Archive":
			handler = "ia"
		elif archive == "Megalodon":
			handler = "mg"

		print("Submitting " + URL + " to " + archive)

		result = archivenow.push(URL, handler)
		
		if len(result) > 0:
			f.write(result[0])
		else:
			print("Unable to archive at this time")
		f.write("\n")


if __name__ == "__main__":
	main()

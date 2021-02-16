from archivenow import archivenow
import time

def main():

	with open("/home/abigail/MemAwareBrowser/src/chrome/browser/ui/bookmarks/archive_url.txt", "w") as f:

		print("Pushing to archive...")
		result = archivenow.push("https://commons.wikimedia.org/wiki/File:PBB_GE_CRYBA1_206982_at_tn.png","is")
		print("Complete!")
		f.write(result[0])


if __name__ == "__main__":
	main()

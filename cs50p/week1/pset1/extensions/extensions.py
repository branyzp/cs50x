text = input("File name: ").replace(" ","").lower()
if '.' in text:
    text = text.split(".")
    match text[len(text)-1]:
        case 'gif' | 'png':
            print("image/" + text[len(text)-1])
        case 'jpg' | 'jpeg':
            print("image/jpeg")
        case 'txt':
            print("text/plain")
        case 'pdf':
            print("application/pdf")
        case 'zip':
            print("application/zip")
        case _:
            print("application/octet-stream")
else:
    print("application/octet-stream")


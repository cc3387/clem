//
//  Choose_Photos.swift
//  Simple
//
//  Created by Clement Chan on 6/4/16.
//  Copyright (c) 2016 Clement Chan. All rights reserved.
//

import UIKit
import Firebase

//Resizing the image before loading
func resizeimage(image: UIImage, targetSize: CGSize) -> UIImage {
    let size = image.size
    
    let widthRatio  = targetSize.width  / image.size.width
    let heightRatio = targetSize.height / image.size.height
    
    // Figure out what our orientation is, and use that to form the rectangle
    var newSize: CGSize
    if(widthRatio > heightRatio) {
        newSize = CGSizeMake(size.width * heightRatio, size.height * heightRatio)
    } else {
        newSize = CGSizeMake(size.width * widthRatio,  size.height * widthRatio)
    }
    
    // This is the rect that we've calculated out and this is what is actually used below
    let rect = CGRectMake(0, 0, newSize.width, newSize.height)
    
    // Actually do the resizing to the rect using the ImageContext stuff
    UIGraphicsBeginImageContextWithOptions(newSize, false, 1.0)
    image.drawInRect(rect)
    let newImage = UIGraphicsGetImageFromCurrentImageContext()
    UIGraphicsEndImageContext()
    
    return newImage
}


//Saving Images after the selection
extension UIImage {
    
    func save(fileName: String, type: String) {
        let documentsPath = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] 
        
        if type.lowercaseString == "png" {
            let path = "\(documentsPath)/\(fileName).\(type)"
            UIImagePNGRepresentation(self)!.writeToFile(path, atomically: true)
        } else if type.lowercaseString == "jpg" {
            let path = "\(documentsPath)/\(fileName).\(type)"
            UIImageJPEGRepresentation(self, 1.0)!.writeToFile(path, atomically: true)
        } else {
            
        }
    }
    
    convenience init?(fileName: String, type: String) {
        let documentsPath = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] 
        let path = "\(documentsPath)/\(fileName).\(type)"
        self.init(contentsOfFile: path)
    }
}

class ChoosePhoto: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    
    @IBOutlet var imageView: UIImageView!
    var base64String: NSString!
    var photonamepath: NSString!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    @IBAction func loadImageButtonTapped(sender: AnyObject) {
        var image = UIImagePickerController()
        image.delegate = self
        image.allowsEditing = false
        image.sourceType = UIImagePickerControllerSourceType.PhotoLibrary
        image.allowsEditing = false
        presentViewController(image, animated: true, completion: nil)
    }
    
    @IBAction func UploadButtons(sender: UIButton) {
        
        //Make a new UIImage
        let uploadImage = UIImage(fileName:"Profile", type:"png")
        
        
        //Make an NSData PNG representation of the Image
        let imageData: NSData = UIImagePNGRepresentation(resizeimage(uploadImage!,targetSize: CGSizeMake(uploadImage!.size.height/5, uploadImage!.size.width/5)))!
        
        //Using base64StringFromData method, we are able to convert data to string
        self.base64String = imageData.base64EncodedStringWithOptions([])
        register_info.Photo = self.base64String as NSString
        print(register_info.Photo)
        loadDestinationVC()
        
    }
        
    func imagePickerController(picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : AnyObject]) {
        if let img = info[UIImagePickerControllerOriginalImage] as? UIImage {
            img.save("Profile", type: "png")
            imageView.image = img
            imageView.contentMode = .ScaleAspectFit
        }
        
        dismissViewControllerAnimated(true, completion: nil)
    }
    
    func imagePickerControllerDidCancel(picker: UIImagePickerController) {
        dismissViewControllerAnimated(true, completion: nil)
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Final_Send", sender: nil)
    }
}
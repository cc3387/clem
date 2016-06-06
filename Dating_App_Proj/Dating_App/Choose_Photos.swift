//
//  Choose_Photos.swift
//  Simple
//
//  Created by Clement Chan on 6/4/16.
//  Copyright (c) 2016 Clement Chan. All rights reserved.
//

import UIKit
import Firebase

//Saving Images after the selection
extension UIImage {
    func save(fileName: String, type: String) {
        let documentsPath = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! String
        
        if type.lowercaseString == "png" {
            let path = "\(documentsPath)/\(fileName).\(type)"
            UIImagePNGRepresentation(self).writeToFile(path, atomically: true)
            println(path);
            
        } else if type.lowercaseString == "jpg" {
            let path = "\(documentsPath)/\(fileName).\(type)"
            UIImageJPEGRepresentation(self, 1.0).writeToFile(path, atomically: true)
            println(path);
        } else {
            
        }
    }
    
    convenience init?(fileName: String, type: String) {
        let documentsPath = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! String
        let path = "\(documentsPath)/\(fileName).\(type)"
        println(path)
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
        
        var ref = Firebase(url: "https://simpleplus.firebaseio.com/")
        
        //Make a new UIImage
        var uploadImage = UIImage(fileName:"Profile", type:"png")
        
        //Make an NSData JPEG representation of the Image
        var imageData: NSData = UIImagePNGRepresentation(uploadImage)
        
        //Using base64StringFromData method, we are able to convert data to string
        self.base64String = imageData.base64EncodedStringWithOptions(.allZeros)
        register_info.Photo = self.base64String
        
        /*var quoteString = ["string": self.base64String]
        var userRef = ref.childByAppendingPath("images")
        var users = ["userid": register_info.username, "images": quoteString]
        userRef.setValue(users)*/
        
        loadDestinationVC()
        
    }
        
    func imagePickerController(picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [NSObject : AnyObject]) {
        
        if let img = info[UIImagePickerControllerOriginalImage] as? UIImage {
            img.save("Profile", type: "png")
            imageView.image = img
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
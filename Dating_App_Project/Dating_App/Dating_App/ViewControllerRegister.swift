//
//  ViewControllerLogin.swift
//  Dating_App
//
//  Created by Clement Chan on 7/8/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class ViewControllerRegister: UIViewController, UITextFieldDelegate,UIPickerViewDataSource, UIPickerViewDelegate{
    
    //TextField Outlet
    @IBOutlet weak var Username: UITextField!
    @IBOutlet weak var Password: UITextField!
    @IBOutlet weak var Email: UITextField!
    @IBOutlet weak var Sender: UIButton!
    @IBOutlet weak var User_Note: UILabel!
    @IBOutlet weak var Password_Not: UILabel!
    @IBOutlet weak var Email_Not: UILabel!
    @IBOutlet weak var Age: UITextField!
    @IBOutlet weak var Location: UITextField!
    @IBOutlet weak var Age_Not: UILabel!
    @IBOutlet weak var Location_Not: UILabel!
    @IBOutlet weak var userexist: UILabel!
    
    //PickerView
    @IBOutlet weak var myPicker: UIPickerView!
    @IBOutlet weak var LocPicker: UIPickerView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myPicker.delegate = self;
        myPicker.dataSource = self;
        //LocPicker.delegate = self;
        //LocPicker.dataSource = self;
        updateAge();
        //updateLoc();
        // Do any additional setup after loading the view, typically from a nib.
    }

    //Register Button Click
    @IBAction func Register(sender: AnyObject) {
        if(self.Username.text == ""){
        self.User_Note.textColor = UIColor.redColor();
        }
        else if (self.Username.text != "" && self.Password.text == ""){
        self.User_Note.textColor = UIColor.clearColor();
        self.Password_Not.textColor = UIColor.redColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text == ""){
        self.User_Note.textColor = UIColor.clearColor();
        self.Password_Not.textColor = UIColor.clearColor();
        self.Email_Not.textColor = UIColor.redColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text == "" && self.Location.text == ""){
        self.User_Note.textColor = UIColor.clearColor();
        self.Password_Not.textColor = UIColor.clearColor();
        self.Email_Not.textColor = UIColor.clearColor();
        self.Age_Not.textColor = UIColor.redColor();
        self.Location_Not.textColor = UIColor.clearColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text != "" && self.Location.text == ""){
        self.User_Note.textColor = UIColor.clearColor();
        self.Password_Not.textColor = UIColor.clearColor();
        self.Email_Not.textColor = UIColor.clearColor();
        self.Age_Not.textColor = UIColor.clearColor();
        self.Location_Not.textColor = UIColor.redColor();
        }
        
        if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text != "" && self.Location.text != "" ){
        self.User_Note.textColor = UIColor.clearColor();
        self.Password_Not.textColor = UIColor.clearColor();
        self.Email_Not.textColor = UIColor.clearColor();
        self.Age_Not.textColor = UIColor.clearColor();
        self.Location_Not.textColor = UIColor.clearColor();
            
            
        //When send button is tappe
        self.Username.endEditing(true);
        self.Password.endEditing(true);
        self.Email.endEditing(true);
        self.Age.endEditing(true);
        self.Location.endEditing(true);
        
        //Create a PF Object
        var user = PFUser()
        var userDetails: PFObject = PFObject(className: "UserDetails")
        //Set the Text Key to the text of the message TextField
        user.username = self.Username.text
        user.password = self.Password.text
        user.email = self.Email.text
        userDetails["username"] = self.Username.text
        userDetails["Age"] = self.Age.text
        userDetails["Profile_Name"] = self.Location.text

        //Save the PFObject, Send to parse
        user.signUpInBackgroundWithBlock {
                (succeeded: Bool, error: NSError?) -> Void in
                if let error = error {
                    let errorString = error.userInfo?["error"] as? NSString
                    // Show the errorString somewhere and let the user try again.
                    self.userexist.textColor = UIColor.redColor();
                    
                } else {
                //Save Details at the user details file as well
                    userDetails.saveInBackgroundWithBlock{
                        
                        (success: Bool, error: NSError?) -> Void in
                        
                        if(success){
                            NSLog("Message Sent Successfully!")
                        }
                            
                        else{
                            NSLog(error!.description)
                        }
                    }
                    
                    register_info.user_id = self.Username.text;
                    register_info.age_range = self.Age.text;
                    
                    //Disable the button and end field
                    self.Username.enabled = false;
                    self.Password.enabled = false;
                    self.Email.enabled = false;
                    self.Age.enabled = false;
                    self.Location.enabled = false;
                    self.Sender.enabled = false;
                    
                    
                    self.Username.text = "";
                    self.Password.text = "";
                    self.Email.text = "";
                    self.Age.text = "";
                    self.Location.text = "";
                    
                    self.loadDestinationVC();
                }
            }
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    enum PickerComponent:Int{
        case age = 0
    }
    
    func updateAge(){
        var sizeComponent = PickerComponent.age.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Age.text = size;
    }
    
    //Picker View, Age Range Functions
    let pickerData = [
        ["18-25","25-30","30-35","35-40", "40-45"]
    ]
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count ;
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        updateAge();
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count;
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row];
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Location_Picker", sender: nil)
    }
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "System Thin", size: 20) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
    
}

//Storing the userid as global variable in the ios app machine
struct register_info{
    static var user_id: String = "";
    static var age_range: String = "";
    static var location: String = "";
    static var address: String = "";
    static var location_lat: Double = 0;
    static var location_lng: Double = 0;
    static var Gender: String = "";
    static var education: String = "";
    static var Major: String = "";
    static var beer_or_wine = "";
    static var sports_or_art = "";
    static var EDC_or_Classic = "";
}

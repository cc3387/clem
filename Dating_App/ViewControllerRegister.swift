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
        self.User_Note.textColor = UIColor.whiteColor();
        self.Password_Not.textColor = UIColor.redColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text == ""){
        self.User_Note.textColor = UIColor.whiteColor();
        self.Password_Not.textColor = UIColor.whiteColor();
        self.Email_Not.textColor = UIColor.redColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text == "" && self.Location.text == ""){
        self.User_Note.textColor = UIColor.whiteColor();
        self.Password_Not.textColor = UIColor.whiteColor();
        self.Email_Not.textColor = UIColor.whiteColor();
        self.Age_Not.textColor = UIColor.redColor();
        self.Location_Not.textColor = UIColor.whiteColor();
        }
        else if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text != "" && self.Location.text == ""){
        self.User_Note.textColor = UIColor.whiteColor();
        self.Password_Not.textColor = UIColor.whiteColor();
        self.Email_Not.textColor = UIColor.whiteColor();
        self.Age_Not.textColor = UIColor.whiteColor();
        self.Location_Not.textColor = UIColor.redColor();
        }
        
        if(self.Username.text != "" && self.Password.text != "" && self.Email.text != "" && self.Age.text != "" && self.Location.text != "" ){
        self.User_Note.textColor = UIColor.whiteColor();
        self.Password_Not.textColor = UIColor.whiteColor();
        self.Email_Not.textColor = UIColor.whiteColor();
        self.Age_Not.textColor = UIColor.whiteColor();
        self.Location_Not.textColor = UIColor.whiteColor();
            
        //When send button is tappe
        self.Username.endEditing(true);
        self.Password.endEditing(true);
        self.Email.endEditing(true);
        self.Age.endEditing(true);
        self.Location.endEditing(true);
            
            
        //Disable the button and end field
        self.Username.enabled = false;
        self.Password.enabled = false;
        self.Email.enabled = false;
        self.Age.enabled = false;
        self.Location.enabled = false;
        self.Sender.enabled = false;
        
        //Create a PF Object
        var userObject: PFObject = PFObject(className: "User")
        var userDetails: PFObject = PFObject(className: "UserDetails")
        
        //Set the Text Key to the text of the message TextField
        userObject["username"] = self.Username.text
        userObject["password"] = self.Password.text
        userObject["email"] = self.Email.text
        userDetails["username"] = self.Username.text
        userDetails["Age"] = self.Age.text
        userDetails["Location"] = self.Location.text

        //Save the PFObject, Send to parse
        userObject.saveInBackgroundWithBlock{
            
            (success: Bool, error: NSError?) -> Void in
            
            if(success){
                NSLog("Message Sent Successfully!")
            }
                
            else{
                NSLog(error!.description)
            }
        }
        
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
        self.Username.text = "";
        self.Password.text = "";
        self.Email.text = "";
        self.Age.text = "";
        self.Location.text = "";
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    enum PickerComponent:Int{
        case age = 0
    }
    
    enum LocComponent:Int{
        case city = 0
    }
    
    func updateAge(){
        var sizeComponent = PickerComponent.age.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Age.text = size;
    }
    
    func updateLoc(){
        var sizeComponent = LocComponent.city.rawValue
        let size = pickerLocData[sizeComponent][LocPicker.selectedRowInComponent(sizeComponent)]
        self.Location.text = size;
    }
    
    //Picker View, Age Range Functions
    let pickerData = [
        ["18-25","25-30","30-35","35-40", "40-45"]
    ]
    
    //Picker View, Location Functions
    let pickerLocData = [
        ["AL", "NY", "NJ"]
    ]
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count ;
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        updateAge();
    }
    
    func pickerLocView(pickerLocView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        updateLoc();
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count;
    }
    
    func pickerLocView(pickerLocView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerLocData[component].count;
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row];
    }
    
    func pickerLocView(pickerLocView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerLocData[component][row];
    }
    
}


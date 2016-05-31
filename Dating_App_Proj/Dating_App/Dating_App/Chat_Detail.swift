//
//  Chat_Detail.swift
//  Simple
//
//  Created by Clement Chan on 12/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

class Chat_Detail : UIViewController, UITableViewDelegate,UITableViewDataSource, UITextFieldDelegate{
    
    //UITables and Buttons
    @IBOutlet weak var MessageTableView: UITableView!
    @IBOutlet weak var MessageTextField: UITextField!
    var chatroom: String = "";
    
    @IBAction func SendButton(sender: AnyObject) {
        
        //Send Button is Tapped
        if(self.MessageTextField.text == "" || self.MessageTextField.text == " " || self.MessageTextField.text == "   "){
        //Do Nothing
        }
        else{
        //Call the End Editing field
        self.MessageTextField.endEditing(true)
        
        //Disable the send button and the textfield
        self.MessageTextField.enabled = false
            
        //Create a PF Object
        var newMessageObject: PFObject = PFObject(className: self.chatroom)
        
        //Set the Text Key to the text of the message TextField
        newMessageObject["Text"] = self.MessageTextField.text
        newMessageObject["From"] = login_user.loginname
        
        //Save the PFObject, Send to parse
        newMessageObject.saveInBackgroundWithBlock{
            
            (success: Bool, error: NSError?) -> Void in
            
            if(success){
                NSLog("Message Sent Successfully!")
            }
                
            else{
                NSLog(error!.description)
            }
            
        }
        
        //Enable the send button and textfield
        self.MessageTextField.enabled = true
        self.MessageTextField.text = ""
        
        //Retrieve Data from Parse
            self.RetrieveMessages();
        }
    }
    //Define arrays that will be used for retrieving information
    var messagesArray:[String] = [String]() //Set an array with empty array
    var senderArray:[String] = [String]() //Set Sender empty Array
    
    //Include all the labels
    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    var friendsArray:[String] = [String]() //Set an array with empty array
    var friend:String = "";
    var read_count: Int = 0;
    
    //Getting Profile name from the server
    
    @IBOutlet weak var Profile_Name: UILabel!
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = login.loginid;
    var user1: String = "";
    
    //Action Item
    override func viewDidLoad() {
        
        println(convo_final.chat_check_final);
        
        //Define Boolean
        if(convo_final.chat_check_final == 1){
            let temp = conversation_info.chat_check1!;
            if(temp == 0){
            convo_final.chat_check_bool = "Y";
            }
            else{
            convo_final.chat_check_bool = "N";
            }
        }
        else if(convo_final.chat_check_final == 2){
            let temp = conversation_info.chat_check2!;
            if(temp == 0){
            convo_final.chat_check_bool = "Y";
            }
            else{
            convo_final.chat_check_bool = "N";
            }
        }
        else if(convo_final.chat_check_final == 3){
            let temp = conversation_info.chat_check3!;
            if(temp == 0){
                convo_final.chat_check_bool = "Y";
            }
            else{
                convo_final.chat_check_bool = "N";
            }
        }
        else if(convo_final.chat_check_final == 4){
            let temp = conversation_info.chat_check4!;
            if(temp == 0){
                convo_final.chat_check_bool = "Y";
            }
            else{
                convo_final.chat_check_bool = "N";
            }
        }
        
        //Defining the chatroom that will be used and retrieved from
        if(convo_final.chat_check_bool == "Y"){
            self.chatroom = login.loginid + convo_final.friend_id_final;
        }
        else if(convo_final.chat_check_bool == "N"){
            self.chatroom = convo_final.friend_id_final + login.loginid;
        }
        
        println("The chatroom is:" + self.chatroom);
        
        //Retrieve information from Parse.com
        //Setting Table View with Delegate and DataSource
        self.MessageTableView.delegate = self  //Set the table view as the delegate
        self.MessageTableView.dataSource = self //Set the table biew as the datasource
        
        //Setting Text Field with Delegate and DataSource
        self.MessageTextField.delegate = self //Handle the Delegate of the TextField
        //Add the tap gesture recognizer to the tableview
        let tapGesture:UITapGestureRecognizer = UITapGestureRecognizer(target:self, action: "TableViewTapped")
        self.MessageTableView.addGestureRecognizer(tapGesture)
        self.RetrieveMessages();
        self.RetrieveMessages();
        
        //Time and other information, Designs for Chatting
        let hours = hour();
        let minutes = minute();
        let hour_i = hour_int();
        let minute_i = minute_Int();
        
        if(hour_i > 6 && hour_i < 12){
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Morning, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Morning, the time is " + hours + " : " + minutes;
            }
            
            Time_Greetings.textColor = UIColor.blackColor();
            Bkground_Image.image = UIImage(named: "malaysia_morning.jpg");
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else if(hour_i >= 12 && hour_i <= 18){
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Afternoon, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Afternoon, the time is " + hours + " : " + minutes;
            }
            
            let random = arc4random_uniform(2);
            
            if(random == 0){
                Bkground_Image.image = UIImage(named: "chicago_afternoon.jpg");
            }
            
            if(random == 1){
                Bkground_Image.image = UIImage(named: "Sunset.jpg");
            }
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else{
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + minutes;
            }
            
            
            let random = arc4random_uniform(1);
            
            if(random == 0){
                Bkground_Image.image = UIImage(named: "night_sky.jpg");
            }
            else if(random == 1){
                Bkground_Image.image = UIImage(named: "hongkongnight.jpg");
            }
            else if(random == 2){
                Bkground_Image.image = UIImage(named: "Paris_Night.jpg");
            }
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.whiteColor();
        }
        
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    //Functions that will be used to display the time
    func hour() -> String
    {
        //Get Hour
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var hours = components.hour
        let hour = String(hours);
        //Return Hour
        return hour
    }
    
    func hour_int() -> Int
    {
        //Get Hour
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var hours = components.hour
        let hour = Int(hours);
        //Return Hour
        return hour
    }
    
    
    func minute() -> String
    {
        //Get Minute
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var minutes = components.minute
        let minute = String(minutes);
        //Return Minute
        return minute
    }
    
    func minute_Int() -> Int
    {
        //Get Minute
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var minutes = components.minute
        let minute = Int(minutes);
        //Return Minute
        return minute
    }
    
    /********************* Function to Retrieve Messages from Parse ******************/

    //This part retrieve the messages saved that were passed on after clicking the "send" button
    func RetrieveMessages(){
        
        //Creating a new PFQuery
        var query = PFQuery(className: self.chatroom)
        
        //Call FindObjectsinBackground
        query.findObjectsInBackgroundWithBlock{
            (objects:[AnyObject]?, error: NSError?) -> Void in
            
            //Clear the Message Array
            self.messagesArray = [String]()
            self.senderArray = [String]()
            
            if let objects = objects as? [PFObject]{
                
                //Loop through the objects array
                for messageObject in objects {
                    
                    //Retrieve the Text column value of each PFObject
                    let messageText:String? = (messageObject as PFObject)["Text"] as? String
                    let Sender:String? = (messageObject as PFObject)["From"] as? String
                    
                    //Assign it into our MessageArray
                    if messageText != nil {
                        self.messagesArray.append(messageText!)
                        self.senderArray.append(Sender!)
                    }
                    
                }
                //Reload the table view
                self.MessageTableView.reloadData()
            }
        }
    }
    
    /****************************** Table Delegate and Methods ******************************/
    //MARK: End Editing when other field is tapped
    func TableViewTapped(){
        //Force the Text Field to end editing
        self.MessageTextField.endEditing(true)
    }
    
    
    //MARK: TextFieldView Delegate and Methods
    func textFieldDidBeginEditing(textField: UITextField) {
        self.view.layoutIfNeeded()
        UIView.animateWithDuration(0.5, animations: {
            self.view.layoutIfNeeded()
            }, completion:nil)
    }
    
    func textFieldDidEndEditing(textField: UITextField) {
        self.view.layoutIfNeeded()
        UIView.animateWithDuration(0.5, animations: {
            self.view.layoutIfNeeded()
            }, completion:nil)
    }
    
    
    //MARK: TableView Delegate and DataSource and Methods
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell{
        //Create a table Cell
        let cell:UITableViewCell = UITableViewCell(style:UITableViewCellStyle.Default, reuseIdentifier:"MessageCell")
        //Customize the Cell
        cell.textLabel?.text = self.messagesArray[indexPath.row] + "   --" + self.senderArray[indexPath.row]
        cell.textLabel!.adjustsFontSizeToFitWidth = true
        cell.textLabel!.minimumScaleFactor = 0.1
        cell.textLabel!.font = UIFont.systemFontOfSize(11.0)
        cell.textLabel!.textColor = UIColor.whiteColor();
        cell.backgroundColor = UIColor.blackColor();
        //Return the Cell
        return cell
    }
    
    //Table method
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return messagesArray.count
    }
    

};
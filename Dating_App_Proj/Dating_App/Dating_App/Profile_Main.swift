//
//  Profile_Main.swift
//  Simple
//
//  Created by Clement Chan on 9/19/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit
import Firebase

class Profile_Main : UIViewController{

    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    var friendsArray:[String] = [String]() //Set an array with empty array
    var friend:String = "";
    var read_count: Int = 0;
    
    //Getting Profile name from the server
    
    @IBOutlet weak var Profile_Name: UILabel!
    
    @IBAction func Single_Meet(sender: AnyObject) {
        loadDestinationVC();
    }
    
    @IBAction func To_Chat(sender: AnyObject) {
        loadtoChat();
    }
    
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = "";
    var user1: String = "";
    
    @IBOutlet var Profile_Pic: UIImageView!
    
    //Action Item
    override func viewDidLoad() {
    super.viewDidLoad()
    self.navigationController?.setNavigationBarHidden(true, animated: false)
    //self.navigationController!.interactivePopGestureRecognizer!.enabled = false
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
            
            let random = arc4random_uniform(3);
            
            Time_Greetings.textColor = UIColor.blackColor();
            
            if(random == 0){
            Bkground_Image.image = UIImage(named: "malaysia_morning.jpg");
            }
            else if(random == 1){
            Bkground_Image.image = UIImage(named: "Switzerland_Bridge.jpg");
            }
            else if(random == 2){
            Bkground_Image.image = UIImage(named: "Dawn_City.jpg");
            }

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
            //self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
            //self.User_ID.textColor = UIColor.blackColor();
        }
        else{
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + minutes;
            }
            
            
            let random = arc4random_uniform(5);
            
            if(random == 0){
            Bkground_Image.image = UIImage(named: "Night_Sky_Pond.jpg");
            }
            else if(random == 1){
            Bkground_Image.image = UIImage(named: "hongkongnight.jpg");
            }
            else if(random == 2){
            Bkground_Image.image = UIImage(named: "Paris_Night.jpg");
            }
            else if(random == 3){
            Bkground_Image.image = UIImage(named: "seattle_night.jpg");
            }
            else if(random == 4){
            Bkground_Image.image = UIImage(named: "New_York_Night.jpg");
            }
            
            //Setting the User ID to login user id
            //self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
            //self.User_ID.textColor = UIColor.whiteColor();
        }
        
        let ref = Firebase(url:"https://simpleplus.firebaseio.com/users")
        ref.queryOrderedByChild("Email").queryEqualToValue(login.loginid)
            .observeEventType(.ChildAdded, withBlock: { snapshot in
                if let login_name = snapshot.value["Profile_Name"] as? String {
                    login_user.loginname = login_name;
                    print(login_user.loginname);
                    self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
                    self.User_ID.textColor = UIColor.whiteColor();
                    
                    if let ulat = snapshot.value["latitude"] as? Double{
                        login_user.latitude = ulat;
                        print(login_user.latitude);
                        if let ulon = snapshot.value["longitude"] as? Double{
                            login_user.longitude = ulon;
                            print(login_user.longitude);
                            if let username = snapshot.value["username"] as? String{
                                login_user.user_name = username;
                                print(login_user.user_name);
                                if let major = snapshot.value["Major"] as? String{
                                    login_user.major = major;
                                    print(login_user.major);
                                    if let university = snapshot.value["Education"] as? String{
                                        login_user.university = university;
                                        print(login_user.university);
                                        if let location = snapshot.value["location"] as? String{
                                            login_user.location = location;
                                            print(login_user.location);
                                            if let ProfileName = snapshot.value["Profile_Name"] as? String{
                                                login_user.Profile_Name = ProfileName;
                                                print(login_user.Profile_Name);
                                                if let base64String = snapshot.value["Photo"] as? String{
                                                    let decodedData = NSData(base64EncodedString: base64String, options: NSDataBase64DecodingOptions())
                                                        let decodedImage = UIImage(data: decodedData!)!
                                                        self.Profile_Pic.image = decodedImage
                                                        self.Profile_Pic.contentMode = .ScaleAspectFit
                                                        login_user.photo = base64String;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            })
        
        //Download all the Friends' emails
        var friend = "https://simpleplus.firebaseio.com/friends/" + login_user.user_name + "_fd";
        let friendemail = Firebase(url:friend)
        frienduser.emailarray = [];
        friendemail.queryOrderedByChild("Email").observeEventType(.Value, withBlock:{friendsnapshot in
            for index in friendsnapshot.children.allObjects as! [FDataSnapshot]{
                if let id = index.value["Email"] as! String?{
                    frienduser.emailarray.append(id);
                }
            }
        })

        //Sending ChatList and Friends to the server before checking on new information
        //let manager = AFHTTPRequestOperationManager()
        
        //Clean up the friendslist
        //var param1 = [
        //]
        
        //var param2 = [
        //    "username":login.loginid
        //]
        
        /*manager.POST("http://localhost:3000/renew",
            
            parameters: param1,
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                print("Successfully renew user info")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                print("fail")
        }
        
        manager.POST("http://localhost:3000/user",
            
            parameters: param2,
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                print("Successfully renew user info")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                print("fail")
        }
        
        manager.GET("http://localhost:3000/user",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                print("Object obtained successfully");
                print(responseObject.count);
                
                if(responseObject.count > 0){
                if let results = responseObject[0] as? NSDictionary {
                    if let Profile_Name = results["Profile_Name"] as? String {
                    login_user.user_name = Profile_Name;
                        login_user.loginname = Profile_Name;
                        if let Profile_Loc = results["location"] as? String {
                            login_user.location = Profile_Loc;
                            if let Profile_Edu = results["Education"] as? String {
                                login_user.university = Profile_Edu;
                                if let Profile_Major = results["Major"] as? String {
                                    login_user.major = Profile_Major;
                                }
                            }
                        }
                     }
                  }
               }
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                print("Error: " + error.localizedDescription)
            }
        )
    
        
        
        //Retrieving the information from parse and append to the friendsArray
        //Creating a new PFQuery
        var query = PFQuery(className: login.loginid + "_chatlist")

        query.findObjectsInBackgroundWithBlock{
            (objects:[AnyObject]?, error: NSError?) -> Void in
            
            //Clear the Message Array
            self.friendsArray = [String]()
            
            if let objects = objects as? [PFObject]{
                
                //Loop through the objects array
                for friendsObject in objects {
                    
                    //Retrieve the Text column value of each PFObject
                    let friends_name:String? = (friendsObject as PFObject)["Friends"] as? String
                    
                    //Assign it into our MessageArray
                    if friends_name != nil {
                        self.friendsArray.append(friends_name!);
                        NSLog(friends_name!);
                        //self.friend = friends_name!;
                   }
                }
                
                print(self.friendsArray.count);
                self.read_count = self.friendsArray.count;
                
                if(self.read_count == 0){
                
                var userchatlist: PFObject = PFObject(className: self.loginuser + "_chatlist");
                    userchatlist["Friends"] = self.loginuser;
                    userchatlist.saveInBackgroundWithBlock{
                        (success: Bool, error: NSError?) -> Void in
                        if(success){
                            NSLog("Friend Saved Successfully!")
                        }
                        else{
                            NSLog(error!.description)
                        }
                    }
                }
                else{
                while(self.read_count > 0){
                self.friend = self.friendsArray[self.read_count - 1];
                var param = [
                    "username":login.loginid,
                    "friend":self.friend
                ]
                
                manager.POST("http://localhost:3000/display_all",
                    
                    parameters: param,
                    //what is needed for success to execute?
                    success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                        print("successfully retrieve user's info")
                    }) { (AFHTTPRequestOperation, NSError) -> Void in
                        print("fail")
                }
              self.read_count -= 1;
              }
            }
          }
        }*/
    }
    
    
    //To Logout and delete token that is assigned
    @IBAction func Logout(sender: AnyObject) {
        
        //print(loginUsername.text)
        let manager = AFHTTPRequestOperationManager()
        
        var params = [
            
            "username":login.loginid,
            "password":login.password
            
        ]
        
        let defaults = NSUserDefaults.standardUserDefaults()
        defaults.setObject(nil, forKey: "token")
        //defaults.getObject(for
        defaults.synchronize()
        
        
        manager.POST("http://localhost:3000/logout",
            parameters: params,
            
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                print("successful logout")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                print("fail")
        }
    }
    
    override func viewWillAppear(animated: Bool) {
        self.navigationController?.navigationBarHidden = true
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    //Functions that will be used to display the time
    func hour() -> String
    {
        //Get Hour
        let date:NSDate = NSDate();
        let calendar: NSCalendar = NSCalendar.currentCalendar();
        let components:NSDateComponents = calendar.components(
            NSCalendarUnit.NSHourCalendarUnit, fromDate: date)
        let hours = components.hour
        let hour = String(hours);
        //Return Hour
        return hour
    }
    
    func hour_int() -> Int
    {
        //Get Hour
        let date:NSDate = NSDate();
        let calendar: NSCalendar = NSCalendar.currentCalendar();
        let components:NSDateComponents = calendar.components(
            NSCalendarUnit.NSHourCalendarUnit, fromDate: date)
        let hours = components.hour
        let hour = Int(hours);
        //Return Hour
        return hour
    }
    
    
    func minute() -> String
    {
        //Get Minute
        let date:NSDate = NSDate();
        let calendar: NSCalendar = NSCalendar.currentCalendar();
        let components:NSDateComponents = calendar.components(
            NSCalendarUnit.NSMinuteCalendarUnit, fromDate: date)
        let minutes = components.minute
        let minute = String(minutes);
        //Return Minute
        return minute
    }
    
    func minute_Int() -> Int
    {
        //Get Minute
        let date:NSDate = NSDate();
        let calendar: NSCalendar = NSCalendar.currentCalendar();
        let components:NSDateComponents = calendar.components(
            NSCalendarUnit.NSMinuteCalendarUnit, fromDate: date)
        let minutes = components.minute
        let minute = Int(minutes);
        //Return Minute
        return minute
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("To_Meet", sender: nil)
    }
    
    func loadtoChat(){
        self.performSegueWithIdentifier("Chat", sender: nil)
    }
};


struct login_user{
    static var user_name: String = "";
    static var Profile_Name: String = "";
    static var loginname: String = "";
    static var location: String = "";
    static var longitude: Double = 0;
    static var latitude: Double = 0;
    static var university: String = "";
    static var major: String = "";
    static var photo: String = "";
};

struct frienduser{
    static var emailarray = [String]();
};

//
//  Meet_Profile.swift
//  Simple
//
//  Created by Clement Chan on 10/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit
import Firebase

class Profile_Meet_Main : UIViewController{
    
    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    //Getting Profile name from the server
    @IBOutlet weak var Profile_Name: UILabel!
    var user_id: String = login.loginid;
    
    //Matching Labels
    @IBOutlet weak var First_Match: UILabel!
    @IBOutlet weak var First_Loc: UILabel!
    @IBOutlet weak var First_Uni: UILabel!
    @IBOutlet weak var First_Major: UILabel!
    var first_id: String = "";
    var first_match: String = "";
    var first_loc: String = "";
    var first_uni: String = "";
    var first_major: String = "";
    
    @IBOutlet weak var Second_Match: UILabel!
    @IBOutlet weak var Second_Loc: UILabel!
    @IBOutlet weak var Second_Uni: UILabel!
    @IBOutlet weak var Second_Major: UILabel!
    var second_id: String = "";
    var second_match: String = "";
    var second_loc: String = "";
    var second_uni: String = "";
    var second_major: String = "";
    
    @IBOutlet weak var Third_Match: UILabel!
    @IBOutlet weak var Third_Loc: UILabel!
    @IBOutlet weak var Third_Uni: UILabel!
    @IBOutlet weak var Third_Major: UILabel!
    var third_id: String = "";
    var third_match: String = "";
    var third_loc: String = "";
    var third_uni:String = "";
    var third_major: String = "";
    
    @IBOutlet weak var Fourth_Match: UILabel!
    @IBOutlet weak var Fourth_Loc: UILabel!
    @IBOutlet weak var Fourth_Uni: UILabel!
    @IBOutlet weak var Fourth_Major: UILabel!
    var fourth_id: String = "";
    var fourth_match: String = "";
    var fourth_loc: String = "";
    var fourth_uni: String = "";
    var fourth_major: String = "";
    
    @IBOutlet weak var Fifth_Match: UILabel!
    
    
    //Buttons to Chat ViewController
    
    @IBAction func Load_Chat_1(sender: AnyObject) {
        
        if(self.first_match != ""){
        var usernamefriend = login_user.user_name + "_fd";
        var friendusername = self.first_id + "_fd";
        var ref = Firebase(url:"https://simpleplus.firebaseio.com")
        var fdref = Firebase(url:"https://simpleplus.firebaseio.com")
        
        var friendinfo = [
            "Profile_Name" : self.First_Match.text!,
            "location" : self.First_Loc.text!,
            "Education": self.First_Uni.text!,
            "Major": self.First_Major.text!,
            "username": self.first_id,
            "Email": self.first_match
        ];
            
        var infofriend = [
            "Profile_Name" : login_user.Profile_Name,
            "location" : login_user.location,
            "Education": login_user.university,
            "Major": login_user.major,
            "username": login_user.user_name,
            "Email": login.loginid
        ];
        
        var usernamefd = ref.childByAppendingPath(usernamefriend);
        var fdusername = fdref.childByAppendingPath(friendusername);
        usernamefd.childByAppendingPath(self.first_id).setValue(friendinfo);
        fdusername.childByAppendingPath(login_user.user_name).setValue(infofriend);
        
//            arrays.friendsArray.append(self.First_Match.text!);
//            arrays.friendlocArray.append(self.First_Loc.text!);
//            arrays.frienduniArray.append(self.First_Uni.text!);
//            arrays.friendmajorArray.append(self.First_Major.text!);
//            arrays.friendidArray.append(self.first_id);
            
        //Load to the next destination
        loadDestinationVC();
        }
        else{
            
        }
    }
    
    @IBAction func Load_Chat_2(sender: AnyObject) {
        
        if(self.second_match != ""){
        var usernamefriend = login_user.user_name + "_fd";
        var friendusername = self.second_id + "_fd";
        var ref = Firebase(url:"https://simpleplus.firebaseio.com")
        var fdref = Firebase(url:"https://simpleplus.firebaseio.com")
        
        var friendinfo = [
            "Profile_Name" : self.Second_Match.text!,
            "location" : self.Second_Loc.text!,
            "Education": self.Second_Uni.text!,
            "Major": self.Second_Major.text!,
            "username": self.second_id,
            "Email": self.second_match
        ];
            
        var infofriend = [
            "Profile_Name" : login_user.Profile_Name,
            "location" : login_user.location,
            "Education": login_user.university,
            "Major": login_user.major,
            "username": login_user.user_name,
            "Email": login.loginid
        ];
        
        var usernamefd = ref.childByAppendingPath(usernamefriend);
        var fdusername = fdref.childByAppendingPath(friendusername);
        usernamefd.childByAppendingPath(self.second_id).setValue(friendinfo);
        fdusername.childByAppendingPath(login_user.user_name).setValue(infofriend);
        
//            arrays.friendsArray.append(self.Second_Match.text!);
//            arrays.friendlocArray.append(self.Second_Loc.text!);
//            arrays.frienduniArray.append(self.Second_Uni.text!);
//            arrays.friendmajorArray.append(self.Second_Major.text!);
//            arrays.friendidArray.append(self.second_id);
            
        //Load to the next destination
        loadDestinationVC();
        }
        else{
            
        }
    }
    
    @IBAction func Load_Chat_3(sender: AnyObject) {
        
        if(self.third_match != ""){
        var usernamefriend = login_user.user_name + "_fd";
        var friendusername = self.second_id + "_fd";
        var ref = Firebase(url:"https://simpleplus.firebaseio.com")
        var fdref = Firebase(url:"https://simpleplus.firebaseio.com")
        
        var friendinfo = [
            "Profile_Name" : self.Third_Match.text!,
            "location" : self.Third_Loc.text!,
            "Education": self.Third_Uni.text!,
            "Major": self.Third_Major.text!,
            "username": self.third_id,
            "Email": self.third_match
        ];
            
        var infofriend = [
            "Profile_Name" : login_user.Profile_Name,
            "location" : login_user.location,
            "Education": login_user.university,
            "Major": login_user.major,
            "username": login_user.user_name,
            "Email": login.loginid
        ];
        
        var usernamefd = ref.childByAppendingPath(usernamefriend);
        var fdusername = fdref.childByAppendingPath(friendusername);
        usernamefd.childByAppendingPath(self.second_id).setValue(friendinfo);
        fdusername.childByAppendingPath(login_user.user_name).setValue(infofriend);
            
//            arrays.friendsArray.append(self.Third_Match.text!);
//            arrays.friendlocArray.append(self.Third_Loc.text!);
//            arrays.frienduniArray.append(self.Third_Uni.text!);
//            arrays.friendmajorArray.append(self.Third_Major.text!);
//            arrays.friendidArray.append(self.third_id);
        
        //Load to the next destination
        loadDestinationVC();
        }
        else{
            
        }
    }
    
    @IBAction func Load_Chat_4(sender: UIButton) {
        
        if(self.fourth_match != ""){
            var usernamefriend = login_user.user_name + "_fd";
            var friendusername = self.second_id + "_fd";
            var ref = Firebase(url:"https://simpleplus.firebaseio.com")
            var fdref = Firebase(url:"https://simpleplus.firebaseio.com")
            
            var friendinfo = [
                "Profile_Name" : self.Fourth_Match.text!,
                "location" : self.Fourth_Loc.text!,
                "Education": self.Fourth_Uni.text!,
                "Major": self.Fourth_Major.text!,
                "username": self.fourth_id,
                "Email": self.fourth_match
            ];
            
            var infofriend = [
                "Profile_Name" : login_user.Profile_Name,
                "location" : login_user.location,
                "Education": login_user.university,
                "Major": login_user.major,
                "username": login_user.user_name,
                "Email": login.loginid
            ];
            
            var usernamefd = ref.childByAppendingPath(usernamefriend);
            var fdusername = fdref.childByAppendingPath(friendusername);
            usernamefd.childByAppendingPath(self.second_id).setValue(friendinfo);
            fdusername.childByAppendingPath(login_user.user_name).setValue(infofriend);
            
            //            arrays.friendsArray.append(self.Fourth_Match.text!);
            //            arrays.friendlocArray.append(self.Fourth_Loc.text!);
            //            arrays.frienduniArray.append(self.Fourth_Uni.text!);
            //            arrays.friendmajorArray.append(self.Fourth_Major.text!);
            //            arrays.friendidArray.append(self.fourth_id);
            
            //Load to the next destination
            loadDestinationVC();
        }
        else{
            
        }
        
    }
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = login.loginid;
    var user1: String = "";
    
    override func viewDidLoad() {
        
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
            self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
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
            self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else{
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + minutes;
            }
            
            
            let random = arc4random_uniform(3);
            
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
            self.User_ID.text = "Welcome to Simple, " + login_user.loginname;
            self.User_ID.textColor = UIColor.whiteColor();
        }
        
        //print(frienduser.emailarray);
        
        //Download all the users to the meeting page
        let ref = Firebase(url:"https://simpleplus.firebaseio.com/users")
        ref.queryOrderedByChild("longitude").queryStartingAtValue(login_user.longitude-1).queryEndingAtValue(login_user.longitude+1)
            .observeEventType(.Value, withBlock: { longitudesnapshot in
                let latref = ref.queryOrderedByChild("latitude").queryStartingAtValue(login_user.latitude-1).queryEndingAtValue(login_user.latitude+1).observeEventType(.Value, withBlock: { latitudesnapshot in
                    
                    var count = 0;
                    
                    for index in latitudesnapshot.children.allObjects as! [FDataSnapshot]{
                        
                        var uname: String = "";
                        var ind: Int = 0;
                        uname = (index.value["Email"] as! String?)!;
                        
                        for friend in frienduser.emailarray{
                            if(uname == friend){
                                ind = 1;
                            }
                        }
                        
                        if(uname != login.loginid && count == 0 && ind == 0){
                        self.First_Match.text = index.value["Profile_Name"] as! String?;
                        self.First_Loc.text = index.value["location"] as! String?;
                        self.First_Uni.text = index.value["Education"] as! String?;
                        self.First_Major.text = index.value["Major"] as! String?;
                        self.first_id = (index.value["username"] as! String?)!;
                        self.first_match = (index.value["Email"] as! String?)!;
                        self.First_Match.textColor = UIColor.whiteColor();
                        self.First_Loc.textColor = UIColor.whiteColor();
                        self.First_Uni.textColor = UIColor.whiteColor();
                        self.First_Major.textColor = UIColor.whiteColor();
                        count += 1;
                        }
                        else if(uname != login.loginid && count == 1 && ind == 0){
                        self.Second_Match.text = index.value["Profile_Name"] as! String?;
                        self.Second_Loc.text = index.value["location"] as! String?;
                        self.Second_Uni.text = index.value["Education"] as! String?;
                        self.Second_Major.text = index.value["Major"] as! String?;
                        self.second_id = (index.value["username"] as! String?)!;
                        self.second_match = (index.value["Email"] as! String?)!;
                        self.Second_Match.textColor = UIColor.whiteColor();
                        self.Second_Loc.textColor = UIColor.whiteColor();
                        self.Second_Uni.textColor = UIColor.whiteColor();
                        self.Second_Major.textColor = UIColor.whiteColor();
                        count += 1;
                        }
                        else if(uname != login.loginid && count == 2 && ind == 0){
                        self.Third_Match.text = index.value["Profile_Name"] as! String?;
                        self.Third_Loc.text = index.value["location"] as! String?;
                        self.Third_Uni.text = index.value["Education"] as! String?;
                        self.Third_Major.text = index.value["Major"] as! String?;
                        self.third_id = (index.value["username"] as! String?)!;
                        self.third_match = (index.value["Email"] as! String?)!;
                        self.Third_Match.textColor = UIColor.whiteColor();
                        self.Third_Loc.textColor = UIColor.whiteColor();
                        self.Third_Uni.textColor = UIColor.whiteColor();
                        self.Third_Major.textColor = UIColor.whiteColor();
                        count += 1;
                        }
                        else if(uname != login.loginid && count == 3 && ind == 0){
                        self.Fourth_Match.text = index.value["Profile_Name"] as! String?;
                        self.Fourth_Loc.text = index.value["location"] as! String?;
                        self.Fourth_Uni.text = index.value["Education"] as! String?;
                        self.Fourth_Major.text = index.value["Major"] as! String?;
                        self.fourth_id = (index.value["username"] as! String?)!;
                        self.fourth_match = (index.value["Email"] as! String?)!;
                        self.Fourth_Match.textColor = UIColor.whiteColor();
                        self.Fourth_Loc.textColor = UIColor.whiteColor();
                        self.Fourth_Uni.textColor = UIColor.whiteColor();
                        self.Fourth_Major.textColor = UIColor.whiteColor();
                        count += 1;
                        }
                    }
                })
        })
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
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("To_Chat", sender: nil)
    }
    
};

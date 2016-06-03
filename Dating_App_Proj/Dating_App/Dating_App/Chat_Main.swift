//
//  Chat_Main.swift
//  Simple
//
//  Created by Clement Chan on 11/15/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit
import Firebase

class Chat_Main : UIViewController{
    
    @IBOutlet weak var Chatroom_title: UILabel!
    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    //Getting Profile name from the server
    @IBOutlet weak var Profile_Name: UILabel!
    
    //Define the variables that will be used in the functions afterwards
    var imagecounter: Int = 0;
    
    
    //Friend_1
    @IBAction func Chat_1(sender: AnyObject) {
    loadDestinationVC();
    }

    @IBOutlet weak var Friend_1: UILabel!
    @IBOutlet weak var Friend_1_Image: UIImageView!

    @IBOutlet weak var Friend_1_Loc: UILabel!
    @IBOutlet weak var Friend_1_Uni: UILabel!
    @IBOutlet weak var Friend_1_Major: UILabel!
    
    //Friend_2
    @IBAction func Chat_2(sender: AnyObject) {
    loadDestinationVC();
    }
    
    @IBOutlet weak var Friend_2: UILabel!
    @IBOutlet weak var Friend_2_Image: UIImageView!
    @IBOutlet weak var Friend_2_Loc: UILabel!
    @IBOutlet weak var Friend_2_Uni: UILabel!
    @IBOutlet weak var Friend_2_Major: UILabel!
    
    //Friend_3
    @IBAction func Chat_3(sender: AnyObject) {
    loadDestinationVC();
    }
    
    @IBOutlet weak var Friend_3: UILabel!
    @IBOutlet weak var Friend_3_Loc: UILabel!
    @IBOutlet weak var Friend_3_Image: UIImageView!
    @IBOutlet weak var Friend_3_Uni: UILabel!
    @IBOutlet weak var Friend_3_Major: UILabel!
    
    //Friend_4
    @IBAction func Chat_4(sender: AnyObject) {
    loadDestinationVC();
    }
    
    @IBOutlet weak var Friend_4: UILabel!
    @IBOutlet weak var Friend_4_Loc: UILabel!
    @IBOutlet weak var Friend_4_Image: UIImageView!
    
    @IBOutlet weak var Friend_4_Uni: UILabel!
    @IBOutlet weak var Friend_4_Major: UILabel!
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = login.loginid;
    var user1: String = "";
    
    //Friend's Array in name, location, university, major and chat check
    var friendsArray:[String] = [String]() //Set an empty array for friend names
    var friendlocArray:[String] = [String]() //Set an empty array for friend locations
    var frienduniArray:[String] = [String]() //Set an empty array for university locations
    var friendmajorArray:[String] = [String]() //Set an empty array for major locations
    var friendidArray:[String] = [String]() //Set an empty array for friend's ID
    var chatcheck:[Int] = [Int]() //Check 1:1 relationship
    
    
    var friend:String = "";
    var read_count: Int = 0;
    var multiple: Int = 0;
    //var multi_count = 1;
    var multi_count_add = 2;
    
    @IBAction func Previous_Button(sender: AnyObject) {
    
        if(self.multiple == 0){
            self.multiple = 0;
        }
        else{
            self.imagecounter -= 1;
            
            if(self.imagecounter <= 0){
            self.imagecounter = 0;
            }
            
            let a = self.friendsArray.count;
            let b = a / 4;
            let remainder = a % 4;
            let page_remainder = a - remainder;
            println(remainder);
            println(b);
            println(self.multi_count_add);
                
                if(b >= 1){
                    self.multi_count_add -= 2;
                    
                    if(self.multi_count_add <= 0){
                    self.multi_count_add = 0;
                    }
                    
                    self.Friend_1.text = self.friendsArray[self.multi_count_add*4+0];
                    self.Friend_1_Loc.text = self.friendlocArray[self.multi_count_add*4+0];
                    self.Friend_1_Uni.text = self.frienduniArray[self.multi_count_add*4+0];
                    self.Friend_1_Major.text = self.friendmajorArray[self.multi_count_add*4+0];
                    self.Friend_2.text = self.friendsArray[self.multi_count_add*4 + 1];
                    self.Friend_2_Loc.text = self.friendlocArray[self.multi_count_add*4+1];
                    self.Friend_2_Uni.text = self.frienduniArray[self.multi_count_add*4+1];
                    self.Friend_2_Major.text = self.friendmajorArray[self.multi_count_add*4+1];
                    self.Friend_3.text = self.friendsArray[self.multi_count_add*4 + 2];
                    self.Friend_3_Loc.text = self.friendlocArray[self.multi_count_add*4+2];
                    self.Friend_3_Uni.text = self.frienduniArray[self.multi_count_add*4+2];
                    self.Friend_3_Major.text = self.friendmajorArray[self.multi_count_add*4+2];
                    self.Friend_4.text = self.friendsArray[self.multi_count_add*4 + 3];
                    self.Friend_4_Loc.text = self.friendlocArray[self.multi_count_add*4+3];
                    self.Friend_4_Uni.text = self.frienduniArray[self.multi_count_add*4+3];
                    self.Friend_4_Major.text = self.friendmajorArray[self.multi_count_add*4+3];
                    conversation_info.friend_id1 = self.friendidArray[self.multi_count_add*4+0];
                    conversation_info.chat_check1 = self.chatcheck[self.multi_count_add*4+0];
                    conversation_info.friend_id2 = self.friendidArray[self.multi_count_add*4+1];
                    conversation_info.chat_check2 = self.chatcheck[self.multi_count_add*4+1];
                    conversation_info.friend_id3 = self.friendidArray[self.multi_count_add*4+2];
                    conversation_info.chat_check3 = self.chatcheck[self.multi_count_add*4+2];
                    conversation_info.friend_id4 = self.friendidArray[self.multi_count_add*4+3];
                    conversation_info.chat_check4 = self.chatcheck[self.multi_count_add*4+3];
                    self.Friend_1.textColor = UIColor.whiteColor();
                    self.Friend_1_Loc.textColor = UIColor.whiteColor();
                    self.Friend_1_Uni.textColor = UIColor.whiteColor();
                    self.Friend_1_Major.textColor = UIColor.whiteColor();
                    self.Friend_2.textColor = UIColor.whiteColor();
                    self.Friend_2_Loc.textColor = UIColor.whiteColor();
                    self.Friend_2_Uni.textColor = UIColor.whiteColor();
                    self.Friend_2_Major.textColor = UIColor.whiteColor();
                    self.Friend_3.textColor = UIColor.whiteColor();
                    self.Friend_3_Loc.textColor = UIColor.whiteColor();
                    self.Friend_3_Major.textColor = UIColor.whiteColor();
                    self.Friend_3_Uni.textColor = UIColor.whiteColor();
                    self.Friend_4.textColor = UIColor.whiteColor();
                    self.Friend_4_Loc.textColor = UIColor.whiteColor();
                    self.Friend_4_Major.textColor = UIColor.whiteColor();
                    self.Friend_4_Uni.textColor = UIColor.whiteColor();
                    
                    if((page_remainder % 4) == 0 && self.multi_count_add >= 1 && (self.multi_count_add - 1) >= 0){
                        self.Friend_1.text = self.friendsArray[(self.multi_count_add-1)*4 + 0];
                        self.Friend_1_Loc.text = self.friendlocArray[(self.multi_count_add-1)*4 + 0];
                        self.Friend_1_Uni.text = self.frienduniArray[(self.multi_count_add-1)*4 + 0];
                        self.Friend_1_Major.text = self.friendmajorArray[(self.multi_count_add-1)*4 + 0];
                        self.Friend_2.text = self.friendsArray[(self.multi_count_add-1)*4 + 1];
                        self.Friend_2_Loc.text = self.friendlocArray[(self.multi_count_add-1)*4 + 1];
                        self.Friend_2_Uni.text = self.frienduniArray[(self.multi_count_add-1)*4 + 1];
                        self.Friend_2_Major.text = self.friendmajorArray[(self.multi_count_add-1)*4 + 1];
                        self.Friend_3.text = self.friendsArray[(self.multi_count_add-1)*4 + 2];
                        self.Friend_3_Loc.text = self.friendlocArray[(self.multi_count_add-1)*4 + 2];
                        self.Friend_3_Uni.text = self.frienduniArray[(self.multi_count_add-1)*4 + 2];
                        self.Friend_3_Major.text = self.friendmajorArray[(self.multi_count_add-1)*4 + 2];
                        self.Friend_4.text = self.friendsArray[(self.multi_count_add-1)*4 + 3];
                        self.Friend_4_Loc.text = self.friendlocArray[(self.multi_count_add-1)*4 + 3];
                        self.Friend_4_Uni.text = self.frienduniArray[(self.multi_count_add-1)*4 + 3];
                        self.Friend_4_Major.text = self.friendmajorArray[(self.multi_count_add-1)*4 + 3];
                        conversation_info.friend_id1 = self.friendidArray[(self.multi_count_add-1)*4 + 0];
                        conversation_info.chat_check1 = self.chatcheck[(self.multi_count_add-1)*4 + 0];
                        conversation_info.friend_id2 = self.friendidArray[(self.multi_count_add-1)*4 + 1];
                        conversation_info.chat_check2 = self.chatcheck[(self.multi_count_add-1)*4 + 1];
                        conversation_info.friend_id3 = self.friendidArray[(self.multi_count_add-1)*4 + 2];
                        conversation_info.chat_check3 = self.chatcheck[(self.multi_count_add-1)*4 + 2];
                        conversation_info.friend_id4 = self.friendidArray[(self.multi_count_add-1)*4 + 3];
                        conversation_info.chat_check4 = self.chatcheck[(self.multi_count_add-1)*4 + 3];
                        self.Friend_1.textColor = UIColor.whiteColor();
                        self.Friend_1_Loc.textColor = UIColor.whiteColor();
                        self.Friend_1_Uni.textColor = UIColor.whiteColor();
                        self.Friend_1_Major.textColor = UIColor.whiteColor();
                        self.Friend_2.textColor = UIColor.whiteColor();
                        self.Friend_2_Loc.textColor = UIColor.whiteColor();
                        self.Friend_2_Uni.textColor = UIColor.whiteColor();
                        self.Friend_2_Major.textColor = UIColor.whiteColor();
                        self.Friend_3.textColor = UIColor.whiteColor();
                        self.Friend_3_Loc.textColor = UIColor.whiteColor();
                        self.Friend_3_Uni.textColor = UIColor.whiteColor();
                        self.Friend_3_Major.textColor = UIColor.whiteColor();
                        self.Friend_4.textColor = UIColor.whiteColor();
                        self.Friend_4_Loc.textColor = UIColor.whiteColor();
                        self.Friend_4_Uni.textColor = UIColor.whiteColor();
                        self.Friend_4_Major.textColor = UIColor.whiteColor();
                    }

                    if(self.multi_count_add == 0){
                    self.multi_count_add = 2;
                    }
                    else{
                    self.multi_count_add -= 1;
                    }
              }
        }
        
        if(self.imagecounter == 0){
            let url = NSURL(string: "https://media.licdn.com/media/p/6/005/0a0/376/1c3abce.jpg")
            let url1 = NSURL(string: "https://media.licdn.com/media/AAEAAQAAAAAAAAjlAAAAJDZkZmE3MDBjLWU3MWEtNGFkNC1hMWQ3LWM0NGZjN2JmMzQyMw.jpg")
            let url2 = NSURL(string:"https://media.licdn.com/media/p/4/000/176/03c/02baf1e.jpg")
            let url3 = NSURL(string:"https://media.licdn.com/media/p/7/005/01d/2f5/3d52f84.jpg")
        self.Friend_1_Image.setImageWithUrl(url!, placeHolderImage: nil);
        self.Friend_2_Image.setImageWithUrl(url1!, placeHolderImage: nil);
        self.Friend_3_Image.setImageWithUrl(url2!, placeHolderImage: nil);
        self.Friend_4_Image.setImageWithUrl(url3!, placeHolderImage: nil);
        }
        
    }
    
    @IBAction func Next_Button(sender: AnyObject) {
            self.imagecounter += 1;
            self.multiple += 4;
            let a = self.friendsArray.count;
            let b = a / 4;
            let remainder = a % 4;
            println(remainder);
            println(b);
            println(self.multi_count_add)
        
        if(self.multi_count_add <= b){
            
            if(self.multi_count_add <= 0){
            self.multi_count_add += 2;
            }
            self.Friend_1.text = self.friendsArray[0 + (self.multi_count_add-1)*4];
            self.Friend_1_Loc.text = self.friendlocArray[0 + (self.multi_count_add-1)*4];
            self.Friend_1_Uni.text = self.frienduniArray[0 + (self.multi_count_add-1)*4];
            self.Friend_1_Major.text = self.friendmajorArray[0 + (self.multi_count_add-1)*4];
            self.Friend_2.text = self.friendsArray[1 + (self.multi_count_add-1)*4];
            self.Friend_2_Loc.text = self.friendlocArray[1 + (self.multi_count_add-1)*4];
            self.Friend_2_Uni.text = self.frienduniArray[1 + (self.multi_count_add-1)*4];
            self.Friend_2_Major.text = self.friendmajorArray[1 + (self.multi_count_add-1)*4];
            self.Friend_3.text = self.friendsArray[2 + (self.multi_count_add-1)*4];
            self.Friend_3_Loc.text = self.friendlocArray[2 + (self.multi_count_add-1)*4];
            self.Friend_3_Uni.text = self.frienduniArray[2 + (self.multi_count_add-1)*4];
            self.Friend_3_Major.text = self.friendmajorArray[2 + (self.multi_count_add-1)*4];
            self.Friend_4.text = self.friendsArray[3 + (self.multi_count_add-1)*4];
            self.Friend_4_Loc.text = self.friendlocArray[3 + (self.multi_count_add-1)*4];
            self.Friend_4_Uni.text = self.frienduniArray[3 + (self.multi_count_add-1)*4];
            self.Friend_4_Major.text = self.friendmajorArray[3 + (self.multi_count_add-1)*4];
            conversation_info.friend_id1 = self.friendidArray[0 + (self.multi_count_add-1)*4];
            conversation_info.chat_check1 = self.chatcheck[0 + (self.multi_count_add-1)*4];
            conversation_info.friend_id2 = self.friendidArray[1 + (self.multi_count_add-1)*4];
            conversation_info.chat_check2 = self.chatcheck[1 + (self.multi_count_add-1)*4];
            conversation_info.friend_id3 = self.friendidArray[2 + (self.multi_count_add-1)*4];
            conversation_info.chat_check3 = self.chatcheck[2 + (self.multi_count_add-1)*4];
            conversation_info.friend_id4 = self.friendidArray[3 + (self.multi_count_add-1)*4];
            conversation_info.chat_check4 = self.chatcheck[3 + (self.multi_count_add-1)*4];
            self.Friend_1.textColor = UIColor.whiteColor();
            self.Friend_1_Loc.textColor = UIColor.whiteColor();
            self.Friend_1_Uni.textColor = UIColor.whiteColor();
            self.Friend_1_Major.textColor = UIColor.whiteColor();
            self.Friend_2.textColor = UIColor.whiteColor();
            self.Friend_2_Loc.textColor = UIColor.whiteColor();
            self.Friend_2_Uni.textColor = UIColor.whiteColor();
            self.Friend_2_Major.textColor = UIColor.whiteColor();
            self.Friend_3.textColor = UIColor.whiteColor();
            self.Friend_3_Loc.textColor = UIColor.whiteColor();
            self.Friend_3_Major.textColor = UIColor.whiteColor();
            self.Friend_3_Uni.textColor = UIColor.whiteColor();
            self.Friend_4.textColor = UIColor.whiteColor();
            self.Friend_4_Loc.textColor = UIColor.whiteColor();
            self.Friend_4_Major.textColor = UIColor.whiteColor();
            self.Friend_4_Uni.textColor = UIColor.whiteColor();
            self.multi_count_add+=1;
        }
        else if(self.multi_count_add > b){
        if(remainder == 1 && b > 0){
            self.Friend_1.text = self.friendsArray[0 + b*4];
            self.Friend_1_Loc.text = self.friendlocArray[0 + b*4];
            self.Friend_1_Uni.text = self.frienduniArray[0 + b*4];
            self.Friend_1_Major.text = self.friendmajorArray[0 + b*4];
            conversation_info.friend_id1 = self.friendidArray[0 + b*4];
            conversation_info.chat_check1 = self.chatcheck[0 + b*4];
            self.Friend_1.textColor = UIColor.whiteColor();
            self.Friend_1_Loc.textColor = UIColor.whiteColor();
            self.Friend_1_Uni.textColor = UIColor.whiteColor();
            self.Friend_1_Major.textColor = UIColor.whiteColor();
            self.Friend_2.textColor = UIColor.clearColor();
            self.Friend_2_Loc.textColor = UIColor.clearColor();
            self.Friend_2_Uni.textColor = UIColor.clearColor();
            self.Friend_2_Major.textColor = UIColor.clearColor();
            self.Friend_3.textColor = UIColor.clearColor();
            self.Friend_3_Loc.textColor = UIColor.clearColor();
            self.Friend_3_Major.textColor = UIColor.clearColor();
            self.Friend_3_Uni.textColor = UIColor.clearColor();
            self.Friend_4.textColor = UIColor.clearColor();
            self.Friend_4_Loc.textColor = UIColor.clearColor();
            self.Friend_4_Major.textColor = UIColor.clearColor();
            self.Friend_4_Uni.textColor = UIColor.clearColor();
            //self.multi_count -= (b-1);
        }
        else if(remainder == 2 && b > 0){
            self.Friend_1.text = self.friendsArray[0 + b*4];
            self.Friend_1_Loc.text = self.friendlocArray[0 + b*4];
            self.Friend_1_Uni.text = self.frienduniArray[0 + b*4];
            self.Friend_1_Major.text = self.friendmajorArray[0 + b*4];
            self.Friend_2.text = self.friendsArray[1 + b*4];
            self.Friend_2_Loc.text = self.friendlocArray[1 + b*4];
            self.Friend_2_Uni.text = self.frienduniArray[1 + b*4];
            self.Friend_2_Major.text = self.friendmajorArray[1 + b*4];
            conversation_info.friend_id1 = self.friendidArray[0 + b*4];
            conversation_info.chat_check1 = self.chatcheck[0 + b*4];
            conversation_info.friend_id2 = self.friendidArray[1 + b*4];
            conversation_info.chat_check2 = self.chatcheck[1 + b*4];
            self.Friend_1.textColor = UIColor.whiteColor();
            self.Friend_1_Loc.textColor = UIColor.whiteColor();
            self.Friend_1_Uni.textColor = UIColor.whiteColor();
            self.Friend_1_Major.textColor = UIColor.whiteColor();
            self.Friend_2.textColor = UIColor.whiteColor();
            self.Friend_2_Loc.textColor = UIColor.whiteColor();
            self.Friend_2_Uni.textColor = UIColor.whiteColor();
            self.Friend_2_Major.textColor = UIColor.whiteColor();
            self.Friend_3.textColor = UIColor.clearColor();
            self.Friend_3_Loc.textColor = UIColor.clearColor();
            self.Friend_3_Major.textColor = UIColor.clearColor();
            self.Friend_3_Uni.textColor = UIColor.clearColor();
            self.Friend_4.textColor = UIColor.clearColor();
            self.Friend_4_Loc.textColor = UIColor.clearColor();
            self.Friend_4_Major.textColor = UIColor.clearColor();
            self.Friend_4_Uni.textColor = UIColor.clearColor();
        }
        else if(remainder == 3 && b > 0){
            self.Friend_1.text = self.friendsArray[0 + b*4];
            self.Friend_1_Loc.text = self.friendlocArray[0 + b*4];
            self.Friend_1_Uni.text = self.frienduniArray[0 + b*4];
            self.Friend_1_Major.text = self.friendmajorArray[0 + b*4];
            self.Friend_2.text = self.friendsArray[1 + b*4];
            self.Friend_2_Loc.text = self.friendlocArray[1 + b*4];
            self.Friend_2_Uni.text = self.frienduniArray[1 + b*4];
            self.Friend_2_Major.text = self.friendmajorArray[1 + b*4];
            self.Friend_3.text = self.friendsArray[2 + b*4];
            self.Friend_3_Loc.text = self.friendlocArray[2 + b*4];
            self.Friend_3_Uni.text = self.frienduniArray[2 + b*4];
            self.Friend_3_Major.text = self.friendmajorArray[2 + b*4];
            conversation_info.friend_id1 = self.friendidArray[0 + b*4];
            conversation_info.chat_check1 = self.chatcheck[0 + b*4];
            conversation_info.friend_id2 = self.friendidArray[1 + b*4];
            conversation_info.chat_check2 = self.chatcheck[1 + b*4];
            conversation_info.friend_id3 = self.friendidArray[2 + b*4];
            conversation_info.chat_check3 = self.chatcheck[2 + b*4];
            self.Friend_1.textColor = UIColor.whiteColor();
            self.Friend_1_Loc.textColor = UIColor.whiteColor();
            self.Friend_1_Uni.textColor = UIColor.whiteColor();
            self.Friend_1_Major.textColor = UIColor.whiteColor();
            self.Friend_2.textColor = UIColor.whiteColor();
            self.Friend_2_Loc.textColor = UIColor.whiteColor();
            self.Friend_2_Uni.textColor = UIColor.whiteColor();
            self.Friend_2_Major.textColor = UIColor.whiteColor();
            self.Friend_3.textColor = UIColor.whiteColor();
            self.Friend_3_Loc.textColor = UIColor.whiteColor();
            self.Friend_3_Major.textColor = UIColor.whiteColor();
            self.Friend_3_Uni.textColor = UIColor.whiteColor();
            self.Friend_4.textColor = UIColor.clearColor();
            self.Friend_4_Loc.textColor = UIColor.clearColor();
            self.Friend_4_Major.textColor = UIColor.clearColor();
            self.Friend_4_Uni.textColor = UIColor.clearColor();
        }
        else if(remainder == 0 && b > 0){
            self.Friend_1.text = self.friendsArray[0 + b*4 - 4];
            self.Friend_1_Loc.text = self.friendlocArray[0 + b*4 - 4];
            self.Friend_1_Uni.text = self.frienduniArray[0 + b*4 - 4];
            self.Friend_1_Major.text = self.friendmajorArray[0 + b*4 - 4];
            self.Friend_2.text = self.friendsArray[1 + b*4 - 4];
            self.Friend_2_Loc.text = self.friendlocArray[1 + b*4 - 4];
            self.Friend_2_Uni.text = self.frienduniArray[1 + b*4 - 4];
            self.Friend_2_Major.text = self.friendmajorArray[1 + b*4 - 4];
            self.Friend_3.text = self.friendsArray[2 + b*4 - 4];
            self.Friend_3_Loc.text = self.friendlocArray[2 + b*4 - 4];
            self.Friend_3_Uni.text = self.frienduniArray[2 + b*4 - 4];
            self.Friend_3_Major.text = self.friendmajorArray[2 + b*4 - 4];
            self.Friend_4.text = self.friendsArray[3 + b*4 - 4];
            self.Friend_4_Loc.text = self.friendlocArray[3 + b*4 - 4];
            self.Friend_4_Uni.text = self.frienduniArray[3 + b*4 - 4];
            self.Friend_4_Major.text = self.friendmajorArray[3 + b*4 - 4];
            conversation_info.friend_id1 = self.friendidArray[0 + b*4-4];
            conversation_info.chat_check1 = self.chatcheck[0 + b*4-4];
            conversation_info.friend_id2 = self.friendidArray[1 + b*4-4];
            conversation_info.chat_check2 = self.chatcheck[1 + b*4-4];
            conversation_info.friend_id3 = self.friendidArray[2 + b*4-4];
            conversation_info.chat_check3 = self.chatcheck[2 + b*4-4];
            conversation_info.friend_id4 = self.friendidArray[3 + b*4-4];
            conversation_info.chat_check4 = self.chatcheck[3 + b*4-4];
            self.Friend_1.textColor = UIColor.whiteColor();
            self.Friend_1_Loc.textColor = UIColor.whiteColor();
            self.Friend_1_Uni.textColor = UIColor.whiteColor();
            self.Friend_1_Major.textColor = UIColor.whiteColor();
            self.Friend_2.textColor = UIColor.whiteColor();
            self.Friend_2_Loc.textColor = UIColor.whiteColor();
            self.Friend_2_Uni.textColor = UIColor.whiteColor();
            self.Friend_2_Major.textColor = UIColor.whiteColor();
            self.Friend_3.textColor = UIColor.whiteColor();
            self.Friend_3_Loc.textColor = UIColor.whiteColor();
            self.Friend_3_Major.textColor = UIColor.whiteColor();
            self.Friend_3_Uni.textColor = UIColor.whiteColor();
            self.Friend_4.textColor = UIColor.whiteColor();
            self.Friend_4_Loc.textColor = UIColor.whiteColor();
            self.Friend_4_Major.textColor = UIColor.whiteColor();
            self.Friend_4_Uni.textColor = UIColor.whiteColor();
        }
      }
        
        if(self.imagecounter == 1){
        let url = NSURL(string: "https://media.licdn.com/media/AAEAAQAAAAAAAAR7AAAAJGU2YjA0NGI2LWMxZTItNDUxZS05ZGQ3LTk2MTVlNjgwNzU4NQ.jpg");
        self.Friend_1_Image.setImageWithUrl(url!, placeHolderImage: nil);
        let url1 = NSURL(string: "https://media.licdn.com/media/p/1/000/188/24d/122c234.jpg");
        self.Friend_2_Image.setImageWithUrl(url1!, placeHolderImage: nil);
        let url2 = NSURL(string: "https://media.licdn.com/media/AAEAAQAAAAAAAAV4AAAAJGZjM2YzODdmLWE5MDUtNDIxYS05OGQ5LTE0ODhkYmU4OWEzOA.jpg");
        self.Friend_3_Image.setImageWithUrl(url2!, placeHolderImage: nil);
        }
        let url3 = NSURL(string: "https://media.licdn.com/media/AAEAAQAAAAAAAAV7AAAAJGJmZjU4MDJkLTBlMTQtNDQxMi04OWNjLTNhMjYyZDM3MjU3YQ.jpg");
        self.Friend_4_Image.setImageWithUrl(url3!, placeHolderImage: nil);
        
    }
    
    
    override func viewDidLoad() {
        
        self.Chatroom_title.backgroundColor = UIColor.clearColor();
        
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
            
            
            let random = arc4random_uniform(0);
            
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
        
        let loginid = "https://simpleplus.firebaseio.com/" + login_user.user_name + "_fd";
        let rref = Firebase(url:loginid);

        rref.observeEventType(.Value, withBlock: { snapshot in
            for index in snapshot.children.allObjects as! [FDataSnapshot]{
                //Retrieve information from firebase
                let friends_name:String? = index.value["Profile_Name"] as? String
                let friends_loc:String? = index.value["location"] as? String
                let friends_uni:String? = index.value["Education"] as? String
                let friends_major:String? = index.value["Major"] as? String
                let friends_id:String? = index.value["Email"] as? String
                
                println(friends_name);
                
                if(friends_name != nil){
                        /*arrays.friendsArray.append(friends_name!);
                        arrays.friendlocArray.append(friends_loc!);
                        arrays.frienduniArray.append(friends_uni!);
                        arrays.friendmajorArray.append(friends_major!);
                        arrays.friendidArray.append(friends_id!);*/
                        self.friendsArray.append(friends_name!);
                        self.friendlocArray.append(friends_loc!);
                        self.frienduniArray.append(friends_uni!);
                        self.friendmajorArray.append(friends_major!);
                        self.friendidArray.append(friends_id!);
                }
            }
            
            self.Friend_1.textColor = UIColor.clearColor();
            self.Friend_1_Loc.textColor = UIColor.clearColor();
            self.Friend_2.textColor = UIColor.clearColor();
            self.Friend_2_Loc.textColor = UIColor.clearColor();
            self.Friend_3.textColor = UIColor.clearColor();
            self.Friend_3_Loc.textColor = UIColor.clearColor();
            self.Friend_4.textColor = UIColor.clearColor();
            self.Friend_4_Loc.textColor = UIColor.clearColor();
            
            //Assigining friend's name
            let a = self.friendsArray.count;
            let remainder = a % 4;
            let b = a/4;
            
            if(self.friendsArray.count == 1){
                self.Friend_1.text = self.friendsArray[0];
                self.Friend_1_Loc.text = self.friendlocArray[0];
                self.Friend_1_Uni.text = self.frienduniArray[0];
                self.Friend_1_Major.text = self.friendmajorArray[0];
                self.Friend_1.textColor = UIColor.whiteColor();
                self.Friend_1_Loc.textColor = UIColor.whiteColor();
                self.Friend_1_Major.textColor = UIColor.whiteColor();
                self.Friend_1_Uni.textColor = UIColor.whiteColor();
            }
            else if(self.friendsArray.count == 2){
                
                self.Friend_1.text = self.friendsArray[0];
                self.Friend_1_Loc.text = self.friendlocArray[0];
                self.Friend_1_Uni.text = self.frienduniArray[0];
                self.Friend_1_Major.text = self.friendmajorArray[0];
                self.Friend_2.text = self.friendsArray[1];
                self.Friend_2_Loc.text = self.friendlocArray[1];
                self.Friend_2_Uni.text = self.frienduniArray[1];
                self.Friend_2_Major.text = self.friendmajorArray[1];
                self.Friend_1.textColor = UIColor.whiteColor();
                self.Friend_1_Loc.textColor = UIColor.whiteColor();
                self.Friend_1_Major.textColor = UIColor.whiteColor();
                self.Friend_1_Uni.textColor = UIColor.whiteColor();
                self.Friend_2.textColor = UIColor.whiteColor();
                self.Friend_2_Loc.textColor = UIColor.whiteColor();
                self.Friend_2_Major.textColor = UIColor.whiteColor();
                self.Friend_2_Uni.textColor = UIColor.whiteColor();
            }
            else if(self.friendsArray.count == 3){
                
                self.Friend_1.text = self.friendsArray[0];
                self.Friend_1_Loc.text = self.friendlocArray[0];
                self.Friend_1_Uni.text = self.frienduniArray[0];
                self.Friend_1_Major.text = self.friendmajorArray[0];
                self.Friend_2.text = self.friendsArray[1];
                self.Friend_2_Loc.text = self.friendlocArray[1];
                self.Friend_2_Uni.text = self.frienduniArray[1];
                self.Friend_2_Major.text = self.friendmajorArray[1];
                self.Friend_3.text = self.friendsArray[2];
                self.Friend_3_Loc.text = self.friendlocArray[2];
                self.Friend_3_Uni.text = self.frienduniArray[2];
                self.Friend_3_Major.text = self.friendmajorArray[2];
                self.Friend_1.textColor = UIColor.whiteColor();
                self.Friend_1_Loc.textColor = UIColor.whiteColor();
                self.Friend_1_Major.textColor = UIColor.whiteColor();
                self.Friend_1_Uni.textColor = UIColor.whiteColor();
                self.Friend_2.textColor = UIColor.whiteColor();
                self.Friend_2_Loc.textColor = UIColor.whiteColor();
                self.Friend_2_Major.textColor = UIColor.whiteColor();
                self.Friend_2_Uni.textColor = UIColor.whiteColor();
                self.Friend_3.textColor = UIColor.whiteColor();
                self.Friend_3_Loc.textColor = UIColor.whiteColor();
                self.Friend_3_Major.textColor = UIColor.whiteColor();
                self.Friend_3_Uni.textColor = UIColor.whiteColor();
                
            }
            else if((remainder == 0 && b > 0) || (remainder == 1 && b > 0) || (remainder == 2 && b > 0) || (remainder == 3 && b > 0)){
                
                self.Friend_1.text = self.friendsArray[0];
                self.Friend_1_Loc.text = self.friendlocArray[0];
                self.Friend_1_Uni.text = self.frienduniArray[0];
                self.Friend_1_Major.text = self.friendmajorArray[0];
                self.Friend_2.text = self.friendsArray[1];
                self.Friend_2_Loc.text = self.friendlocArray[1];
                self.Friend_2_Uni.text = self.frienduniArray[1];
                self.Friend_2_Major.text = self.friendmajorArray[1];
                self.Friend_3.text = self.friendsArray[2];
                self.Friend_3_Loc.text = self.friendlocArray[2];
                self.Friend_3_Uni.text = self.frienduniArray[2];
                self.Friend_3_Major.text = self.friendmajorArray[2];
                self.Friend_4.text = self.friendsArray[3];
                self.Friend_4_Loc.text = self.friendlocArray[3];
                self.Friend_4_Uni.text = self.frienduniArray[3];
                self.Friend_4_Major.text = self.friendmajorArray[3];
                self.Friend_1.textColor = UIColor.whiteColor();
                self.Friend_1_Loc.textColor = UIColor.whiteColor();
                self.Friend_1_Major.textColor = UIColor.whiteColor();
                self.Friend_1_Uni.textColor = UIColor.whiteColor();
                self.Friend_2.textColor = UIColor.whiteColor();
                self.Friend_2_Loc.textColor = UIColor.whiteColor();
                self.Friend_2_Major.textColor = UIColor.whiteColor();
                self.Friend_2_Uni.textColor = UIColor.whiteColor();
                self.Friend_3.textColor = UIColor.whiteColor();
                self.Friend_3_Loc.textColor = UIColor.whiteColor();
                self.Friend_3_Major.textColor = UIColor.whiteColor();
                self.Friend_3_Uni.textColor = UIColor.whiteColor();
                self.Friend_4.textColor = UIColor.whiteColor();
                self.Friend_4_Loc.textColor = UIColor.whiteColor();
                self.Friend_4_Major.textColor = UIColor.whiteColor();
                self.Friend_4_Uni.textColor = UIColor.whiteColor();
            }
        })
            //Testing with erik's photo online
            let url = NSURL(string: "https://media.licdn.com/media/p/6/005/0a0/376/1c3abce.jpg")
            let url1 = NSURL(string: "https://media.licdn.com/media/AAEAAQAAAAAAAAjlAAAAJDZkZmE3MDBjLWU3MWEtNGFkNC1hMWQ3LWM0NGZjN2JmMzQyMw.jpg")
            let url2 = NSURL(string:"https://media.licdn.com/media/p/4/000/176/03c/02baf1e.jpg")
            let url3 = NSURL(string:"https://media.licdn.com/media/p/7/005/01d/2f5/3d52f84.jpg")
            self.Friend_1_Image.setImageWithUrl(url!, placeHolderImage: nil);
            self.Friend_2_Image.setImageWithUrl(url1!, placeHolderImage: nil);
            self.Friend_3_Image.setImageWithUrl(url2!, placeHolderImage: nil);
            self.Friend_4_Image.setImageWithUrl(url3!, placeHolderImage: nil);
        
    }

    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Show_Chat_Detail", sender: nil)
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
};

struct conversation_info{
    static var friend_id1: String? = "";
    static var friend_id2: String? = "";
    static var friend_id3: String? = "";
    static var friend_id4: String? = "";
    static var chat_check1: Int?;
    static var chat_check2: Int?;
    static var chat_check3: Int?;
    static var chat_check4: Int?;
};

struct convo_final{
    static var friend_id_final: String = "";
    static var chat_check_bool: String = "";
    static var chat_check_final: Int?;

};


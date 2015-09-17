//
//  Beer_Wine.swift
//  Simple
//
//  Created by Clement Chan on 9/4/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class BeerWine: UIViewController{
    
    override func viewDidLoad() {
        
        var leftSwipe = UISwipeGestureRecognizer(target: self, action: ("BeerWineSwipes:"))
        var rightSwipe = UISwipeGestureRecognizer(target: self, action: ("BeerWineSwipes:"))
        
        leftSwipe.direction = .Left
        rightSwipe.direction = .Right
        
        view.addGestureRecognizer(leftSwipe)
        view.addGestureRecognizer(rightSwipe)
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func BeerWineSwipes(sender:UISwipeGestureRecognizer){
        
        if(sender.direction == .Right){
            register_info.beer_or_wine = "Wine"
            println(register_info.beer_or_wine)
            loadDestinationVC()
           
        }
        else if(sender.direction == .Left){
            register_info.beer_or_wine = "Beer"
            println(register_info.beer_or_wine)
            loadDestinationVC()
        }
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("SportsArt", sender: nil)
    }
    
}

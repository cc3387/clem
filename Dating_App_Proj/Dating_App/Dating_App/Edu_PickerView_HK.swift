//
//  Edu_PickerView.swift
//  Simple
//
//  Created by Clement Chan on 7/26/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class Edu_PickerView_HK: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    
    @IBOutlet weak var myPicker: UIPickerView!
    
    @IBAction func next_quest(sender: AnyObject) {
        updateLoc();
        loadDestinationVC();
    }
    
    var Edu: String = "";
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myPicker.delegate = self;
        myPicker.dataSource = self;
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateLoc(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Edu = size;
        register_info.education = self.Edu;
        println(register_info.education);
    }
    
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }
    
    let pickerData = [
        [
         "University of Hong Kong",
         "The Chinese University of Hong Kong",
         "Hong Kong Polytechnic University",
         "City University of Hong Kong",
         "Hong Kong University of Science and Technology",
         "Hong Kong Baptist University",
         "Hong Kong Shue Yan University",
         "Hong Kong Institute of Education"
        ]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Major_HK", sender: nil)
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "System Thin", size: 10) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
}

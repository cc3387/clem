//
//  PickerViewTest.swift
//  Dating_App
//
//  Created by Clement Chan on 7/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class Loc_PickerView: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    @IBOutlet weak var myPicker: UIPickerView!
    var Loc: String = "";

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
    
    @IBAction func Nextq(sender: AnyObject) {
        updateLoc();
        loadDestinationVC();
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Google_Loc", sender: nil)
    }
    
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateLoc(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Loc = size;
        register_info.location = self.Loc;
        println(register_info.location);
    }
    
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }
    
    let pickerData = [
        ["New York NY","Los Angeles CA","Chicago IL","Houston TX", "Phoenix AZ"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
}




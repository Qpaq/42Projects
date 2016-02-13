//
//  ListPlacesTableViewCell.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import UIKit

class ListPlacesTableViewCell: UITableViewCell {

    
    @IBOutlet weak var namePlaceLabel: UILabel!
    @IBOutlet weak var imagePlaceCell: UIImageView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
        imagePlaceCell.image = UIImage(named: "cell-arrow")
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}

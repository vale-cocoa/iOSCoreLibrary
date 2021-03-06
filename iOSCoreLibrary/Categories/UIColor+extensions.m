//
//  UIColor+extensions.m
//  iOSCoreLibrary
//
//  Created by Iain McManus on 1/07/13.
//
//

#import "UIColor+extensions.h"

#if TARGET_OS_IPHONE

@implementation UIColor (extensions)

- (NSString*) hexString {
    CGFloat red, green, blue, alpha;
    [self getRed:&red green:&green blue:&blue alpha:&alpha];
    
    return [NSString stringWithFormat:@"#%02X%02X%02X%02X", (int)(red * 255), (int)(green * 255), (int)(blue * 255), (int)(alpha * 255)];
}

- (NSString*) htmlHexString {
    CGFloat red, green, blue, alpha;
    [self getRed:&red green:&green blue:&blue alpha:&alpha];
    
    return [NSString stringWithFormat:@"#%02X%02X%02X", (int)(red * 255), (int)(green * 255), (int)(blue * 255)];
}

+ (UIColor*) fromHexString:(NSString*) inHexString {
    if ([inHexString length] == 0) {
        return [UIColor magentaColor];
    }
    
    unsigned int red, green, blue, alpha;
    unsigned int offset = 0;
    
    if ([inHexString characterAtIndex:0] == '#') {
        offset = 1;
    }
    
    NSString* redString = [inHexString substringWithRange:NSMakeRange(0 + offset, 2)];
    [[NSScanner scannerWithString:redString] scanHexInt:&red];
    
    NSString* greenString = [inHexString substringWithRange:NSMakeRange(2 + offset, 2)];
    [[NSScanner scannerWithString:greenString] scanHexInt:&green];
    
    NSString* blueString = [inHexString substringWithRange:NSMakeRange(4 + offset, 2)];
    [[NSScanner scannerWithString:blueString] scanHexInt:&blue];
    
    NSString* alphaString = [inHexString substringWithRange:NSMakeRange(6 + offset, 2)];
    [[NSScanner scannerWithString:alphaString] scanHexInt:&alpha];
    
    return [UIColor colorWithRed:red/255.0f green:green/255.0f blue:blue/255.0f alpha:alpha/255.0f];
}

- (CGFloat) perceivedBrightness {
    CGColorSpaceRef colourSpace = CGColorGetColorSpace(self.CGColor);
    CGColorSpaceModel colourSpaceModel = CGColorSpaceGetModel(colourSpace);
    
    if (colourSpaceModel == kCGColorSpaceModelRGB) {
        CGFloat red, green, blue, alpha;
        
        [self getRed:&red green:&green blue:&blue alpha:&alpha];
        
        // calculate perceived brightness based on W3C formula
        // http://www.w3.org/TR/AERT#color-contrast
        return (red * 0.299) + (green * 0.587) + (blue * 0.111);
    }
    else {
        CGFloat white, alpha;
        
        [self getWhite:&white alpha:&alpha];
        
        return white;
    }
}

- (UIColor*) autoGenerateDifferentShade {
    CGFloat hue, saturation, brightness, alpha;
    
    [self getHue:&hue saturation:&saturation brightness:&brightness alpha:&alpha];
    
    // special case for black
    if (brightness == 0) {
        hue = 0;
        saturation = 0;
        brightness = 0.75f;
    } // special case for grey
    else if (saturation == 0) {
        if (brightness <= 0.5f) {
            brightness = 0.75f;
        }
        else {
            brightness = 0.25f;
        }
    }
    else {
        if (brightness <= 0.5f) {
            brightness = 0.95f;
        }
        else {
            brightness = 0.25f;
        }
        
        if (saturation >= 0.75f) {
            saturation = 0.25f;
        }
        else {
            saturation = 0.75f;
        }
    }
    
    return [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
}

- (UIColor*) autoGenerateLighterShade {
    CGFloat hue, saturation, brightness, alpha;
    
    [self getHue:&hue saturation:&saturation brightness:&brightness alpha:&alpha];
    
    // special case for black
    if (brightness == 0) {
        hue = 0;
        saturation = 0;
        brightness = 0.75f;
    } // special case for grey
    else if (saturation == 0) {
        brightness = 0.75f;
    }
    else {
        brightness = 0.95f;
        saturation = 0.35f;
    }
    
    return [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
}

- (UIColor*) autoGenerateMuchLighterShade {
    CGFloat hue, saturation, brightness, alpha;
    
    [self getHue:&hue saturation:&saturation brightness:&brightness alpha:&alpha];
    
    // special case for black
    if (brightness == 0) {
        hue = 0;
        saturation = 0;
        brightness = 1.0f;
    } // special case for grey
    else if (saturation == 0) {
        brightness = 1.0f;
    }
    else {
        brightness = 0.95f;
        saturation = 0.15f;
    }
    
    return [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
}

@end

#endif // TARGET_OS_IPHONE
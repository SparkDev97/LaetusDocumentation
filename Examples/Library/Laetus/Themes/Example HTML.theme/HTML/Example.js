function CreateRipple(x, y)
{
    var posX = $(".box").offset().left;
    var posY = $(".box").offset().top;
    var contentWidth = $(".box").width();
    var contentHeight =  $(".box").height();
    
    var ripple = $("<span class='ripple'></span>");
    $(".box").prepend(ripple);
  
    if(contentWidth >= contentHeight) 
    {
        contentHeight = contentWidth;
    } 
    else 
    {
        contentWidth = contentHeight; 
    }
    
    var x = x - posX - contentWidth / 2;
    var y = y - posY - contentHeight / 2;
   
    ripple.css({
      width: contentWidth,
      height: contentHeight,
      top: y + 'px',
      left: x + 'px'
    }).addClass("rippleEffect");

    setTimeout(function(){
        ripple.remove();
    }, 1000);
}

function laetusDidTouchDown(x, y)
{
    CreateRipple(x, y);
}
jQuery(document).ready(function($) {
	jQuery.fn.exists = function(){ return this.length>0; }
	
	/* Menu */
	ddsmoothmenu.init({
		mainmenuid: "mainmenu", //menu DIV id
		orientation: 'h', //Horizontal or vertical menu: Set to "h" or "v"
		classname: 'ddsmoothmenu', //class added to menu's outer DIV
		contentsource: "markup" //"markup" or ["container_id", "path_to_menu_file"]
	});

	/* FancyBox 2 */
	addFancyBox();

	/* Responsive Menu Generation */
    menuHandler();

	/* Responsive Select Menu */
	jQuery("#responsive-menu select").change(function() {
		window.location = jQuery(this).find("option:selected").val();
	});

	/* Activate Tabs */
	jQuery('.themetab a').click(function (e) {
		e.preventDefault();
		jQuery(this).tab('show');
	})

	/* Activate Carousels */
	jQuery('.carousel').carousel({ interval: 5000 })

	/* Fit Videos */
	jQuery(".scalevid").fitVids();

	/* Tooltips */
	jQuery("a[data-rel^='tooltip']").tooltip();
	jQuery("div.projectnav[data-rel^='tooltip']").tooltip();

	/* Popovers */
	jQuery("a[data-rel^='popover']").popover();

	/* Collapse Extra Functions */
	initCollapseExtras();

	/* Team Member Adjustement */
	initTeamMemberAdjustment();

	jQuery(window).resize(function() {

		initTeamMemberAdjustment();
		/*menuLineAdjustment();*/

	})

	/*Fancy Box Build Group */
	$('.portfoliofilter a').on('click',function() {

		setTimeout(function() {

		   $('.portfolio.isotope').find('.isotope-item').each(function() {
		   		$(this).find('.fancybox').data('rel','fancygroup');
		   		$(this).find('.fancybox').attr('rel','fancygroup');
		     });
		   $('.portfolio.isotope').find('.isotope-hidden').each(function() {
		   		$(this).find('.fancybox').data('rel','hiddengroup');
		   		$(this).find('.fancybox').attr('rel','hiddengroup');
		     });

		 },500);
	});
	
	/* GOOGLE MAPS */

	if (jQuery('.map').exists()) {
		var container = jQuery(".map");
		if (container.length == 0){ return; } 
		var mapInner = jQuery('.map');	
		var coordinate = new google.maps.LatLng(container.data("lat"), container.data("lon"));

		var mapOptions = {
				center: coordinate,
				zoom: 15,
				mapTypeId: google.maps.MapTypeId.ROADMAP,
				mapTypeControl: false
		};

		var map = new google.maps.Map(mapInner.get(0), mapOptions);

		var myMarker = new google.maps.Marker({
			position: coordinate,
			map: map,
		});
	}
	
	/* RETINA ICONS */

	if (jQuery('ul.retina-icons').exists()) {
		jQuery('ul.retina-icons li > i').each(function() {
			$class = jQuery(this).attr("class");
			jQuery(this).attr('data-rel', 'tooltip').attr('data-title', $class).attr('data-placement', 'bottom').tooltip();
		});
	}
	
	/* MODIFY PAGINATOR */
	
	if ($('.pager').exists()) {
		var $pages = 0,
			$current = $('.pager-current').text(),
			$parent = $('.pager').parent();
		
		$('.pager-item, .pager-current').each(function() {
			$pages++;
		});
		
		$parent.addClass('pagination').before('<div class="pagenumbers">Page '+$current+ ' of '+$pages+'</div>');
		$('.pager').removeClass('pager');
		$('.pager-current').wrapInner('<span />');

	}

	/* CARE ABOUT THE INPUT FIELDS */
	initInputFields();

	/*WAIT FOR SLIDER LOADER*/
	if (jQuery('.front').exists()) {
		initSliderFun();
		initSliderHeight();
	}
	
	if (jQuery('.messages').exists()) {
		jQuery('.messages:last').css('margin-bottom', '20px');
	}
	
	/* STICKY HEADER */

	if (jQuery('.sticky-header').exists()) {

	    $(window).resize(function() {
	    	var $top = $('.headertopwrap').height() + 3;   
	        if ($(this).scrollTop() >= $top) {
				$('.headerwrap').addClass('fixed');
				$('.headerwrap').css('margin-top', -$top+'px');
			} else {
				$('.headerwrap').removeClass('fixed');
				$('.headerwrap').css('margin-top', 'inherit');
			}
	    });
	    
	    $(document).scroll( function() {
	    	var $top = $('.headertopwrap').height() + 3;   
	        if ($(this).scrollTop() >= $top) {
				$('.headerwrap').addClass('fixed');
				$('.headerwrap').css('margin-top', -$top+'px');
			} else {
				$('.headerwrap').removeClass('fixed');
				$('.headerwrap').css('margin-top', 'inherit');
			}
	    });		
	}
});

		/******************************
			-	SLIDER FUN ;-)	-
		********************************/
		function initSliderFun() {
			// CHANGE HEIGHT OF DEF CONTAINER
			if(!is_mobile()){
				jQuery('.region.header.parallax').css({height:'auto'});			
				jQuery('.parallax #revolution_slider_1 ul li').each(function() {
					jQuery(this).find('.caption').each(function(){
						if(jQuery(this).html().lastIndexOf("vimeo")>-1 || jQuery(this).html().lastIndexOf("vimeo")>-1 || jQuery(this).html().lastIndexOf("href")>-1)
							zindex = "50001";
						else 
						 	zindex = "1";
						jQuery(this).wrap('<div class="tp-parallax" style="position:absolute;width:100%;height:100%;top:0px;left:0px;z-index:'+zindex+';"></div>');
						
					});
				});
			
			jQuery(window).scroll(function() {			

				var offset = jQuery(window).scrollTop();
					jQuery('#revolution_slider_1 .tp-parallax').each(function() {
						var tp=jQuery(this);
						TweenLite.to(tp,0.3,{z:1000,scale:1, rotationX:offset/10,z:0.01,transformOrigin:"center bottom",opacity:1-Math.abs(offset/1000),transformPerspective:1000,top:offset/2,ease:Linear.easeNone});	
						if(navigator.userAgent.indexOf('Chrome') > -1){
							tp.css("-webkit-transform-origin",'none');
							tp.css("-webkit-transform",'none');			
						}
					});

			});
			}
		}
		
		function initSliderHeight(){
			jQuery('.region.header').css({height:'auto'});
		}

		///////////////////////
		// INIT INPUT FIELDS //
		//////////////////////

		function initInputFields() {

			// Check the Search value on Standard
				jQuery(".prepared-input, .searchinput").each(function() {
					var field=jQuery(this);
					field.data('standard',field.val());
				});


				jQuery(".prepared-input, .searchinput").focus(function(){
					var $this = jQuery(this);

					$this.val($this.val()== $this.data('standard') ? "" : $this.val());
				});
				jQuery(".prepared-input, .searchinput").blur(function(){
					var $this = jQuery(this);
					$this.val($this.val()== "" ? $this.data('standard') : $this.val());
				});
		}


/*************************************
	-	MENU WIDTH ADJUSTMENT   -
**************************************/
	function menuWidthAdjustment() {
		/*jQuery('.ddsmoothmenu ul li').each(function() {
			var li=jQuery(this);
			var maxwidth=0;

			li.hover(function() {
				maxwidth=0;
				var li=jQuery(this);

				setTimeout(function() {

					li.find('>ul>li>a').each(function() {

						if (maxwidth < jQuery(this).innerWidth()) maxwidth = jQuery(this).width();
					})

					maxwidth=maxwidth+40;
					li.find('ul').css({width:maxwidth+"px"});
					li.find('ul ul').each(function() {
						console.log(jQuery(this).css('left'));
						jQuery(this).css({left:maxwidth+"px"});

					});

				},1);

			})
		})*/
	}

/* Team Member Adjustement */
function initTeamMemberAdjustment() {
	var maxh=0;
	var padds=0;
//	jQuery('.team').waitForImages(function() {
//		jQuery('.team').find('.memberwrap').each(function() {
//			var th=jQuery(this);
//			padds=parseInt(th.css('paddingBottom'),0) + parseInt(th.css('paddingTop'),0);
//			if (maxh<th.find('.member').outerHeight(true)) maxh=th.find('.member').outerHeight(true);
//		})
//
//
//
//		jQuery('.team').find('.memberwrap').each(function() {
//			jQuery(this).css({'height':(maxh+padds)+"px"});
//		})
//	});
}

/* Sticky Header */

function initStickyHeader(){
    var navIsBig = true;
    var $nav = $('nav');
    var $logo = $('.logo img');
    var $height = $logo.height()
    
    $(document).scroll( function() {
        var value = $(this).scrollTop();
       
        if ( value > 100 && navIsBig ){
            $nav.animate({height:45},"slow");
                    $logo.animate({height:($height * 0.8)},"slow");
            navIsBig = false;
            
        }
        else if (value <= 100 && !navIsBig ) {
           $nav.animate({height:100},"slow");
           $logo.animate({height:($height * 1)},"slow");
            navIsBig = true;
        }
    });
}

/* INITIALISE  THE COLLAPSE FUNCTIONS */
function initCollapseExtras() {
	jQuery('.accordion-toggle').each(function() {
		jQuery(this).click(function() {
			jQuery(this).closest('.accordion').find('.accordion-toggle').each(function(i) {
				//alert(i)
				jQuery(this).addClass('collapsed');
			})
		})
	})
}

/* #Fancy Box
================================================== */

function addFancyBox() {
	/* PrettyPhoto init */

	jQuery(".prettyphoto").each(function(){
		jQuery(this).removeClass("prettyphoto").addClass("fancybox").attr("rel","gallery");
	});

	jQuery(".fancybox").fancybox({
		openEffect  : 'none',
		closeEffect : 'none',
		autoResize : true,
		fitToView : true,
		helpers : {
			media : {}
		}
	});

	jQuery(window).resize(function() {
		jQuery.fancybox.update();
	});
}

/* #Menu Handler
================================================== */

function menuHandler() {

	var defpar = jQuery('#mainmenu').parents().length;

	jQuery('#mainmenu li > a').each(function() {
		var a=jQuery(this);
		var par= a.parents().length-defpar -3;

		var atext = a.html().split('<')[0];
		atext = atext.toLowerCase();
		atext = atext.substr(0,1).toUpperCase() + atext.substr(1,atext.length);

		if (par==0)
			var newtxt=jQuery("<div>"+atext+"</div>").text();
		else
			if (par==2)
				var newtxt=jQuery("<div>&nbsp;&nbsp;&nbsp;"+atext+"</div>").text();
			else
				if (par==4)
					var newtxt=jQuery("<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+atext+"</div>").text();

		 jQuery('#responsive-menu select').append(new Option(newtxt,a.attr('href')) );
	});
}

/*#Footer Handler
================================================== */
function footerHandler() {

	var footer_wrap = jQuery('body').find('.footerwrap');

	jQuery(window).resize(function() {
		footerAdjust();
		setTimeout(function() {footerAdjust();},100);
	});

	var intfa_c=0;
	var intfa=setInterval(function() {
		footerAdjust();
		intfa_c++;
		if (intfa_c>15) clearInterval(intfa);
	},100);

	function footerAdjust(){

		var footerh = footer_wrap.outerHeight();
		var windowh = jQuery(window).height();
		dif=0;
		if(footer_wrap.length){
			dif =  parseInt(footer_wrap.css('marginTop'),0) + Math.round(windowh - (footer_wrap.offset().top + footerh));
			if (dif>0) {
				footer_wrap.stop();
				footer_wrap.animate({'marginTop':dif+"px"},{duration:300,queue:false});
			}
			if (dif<0) {
				footer_wrap.stop(true,true);
				footer_wrap.animate({'marginTop':"0px"},{duration:300,queue:false});
			}
		}


	};



}


// Check Mobile
	function is_mobile() {
	      var agents = ['android', 'webos', 'iphone', 'ipad', 'blackberry','Android', 'webos', ,'iPod', 'iPhone', 'iPad', 'Blackberry', 'BlackBerry'];
	   var ismobile=false;
	      for(i in agents) {
	
	       if (navigator.userAgent.split(agents[i]).length>1) {
	              ismobile = true;
	            
	            }
	      }
	      return ismobile;
	  }
	
	function initStickyHeader(){
	    var navIsBig = true;
	    var $nav = $('.headerwrap');
	    var $logo = $('.logo img');
	    var $height = $logo.height()
	    
	    $(document).scroll( function() {
	        var value = $(this).scrollTop();
	       
	        if ( value > 100 && navIsBig ){
	            $nav.animate({height:45},"slow");
	                    $logo.animate({height:($height * 0.8)},"slow");
	            navIsBig = false;
	            
	        }
	        else if (value <= 100 && !navIsBig ) {
	           $nav.animate({height:100},"slow");
	           $logo.animate({height:($height * 1)},"slow");
	            navIsBig = true;
	        }
	    });
	}
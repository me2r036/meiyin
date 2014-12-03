jQuery(document).ready(function (e) {
    jQuery.fn.exists = function () {
        return this.length > 0
    };
    
    e('table td a:contains("export")').parent().remove();
    e('#edit-label-machine-name-suffix').remove();
    
    if (e(".field-type-revolution-slider-layer").exists()) {
        var t = e("#edit-field-image .image-widget span.file").find("a").attr("href");
        $subLayer = e(".field-type-revolution-slider-layer table.field-multiple-table tr.draggable:not(:last)");
        $first = e(".field-type-revolution-slider-layer table.field-multiple-table tr.draggable:first");
        $last = e(".field-type-revolution-slider-layer table.field-multiple-table tr.draggable:last");
        $current = 0;
        $width = e(".dimensions" ).data( "width" );
        $height = e(".dimensions" ).data( "height" );
        e(".field-type-revolution-slider-slide").after('<div class="preview-bg" />');
        e("div.preview-bg").css("background-image", "url(" + t + ")").wrap('<div class="slide-builder" />');
        e(".slide-builder").prepend("<label>Preview</label>");
        var n = new Image;
        n.onload = function () {
            e(".slide-builder").width(e(".slide-builder").parent().width());
            e("div.preview-bg").css("width", $width).css("height", $height).css("background-position", "center");
            if (this.width > e("slide-builder").parent().width()) {}
        };
        n.src = t;
        $first.show();
        $last.hide();
        $subLayer.each(function () {
            var t = e(this).find("input.edit-revolution_slider-fields-data-x").val();
            $y = e(this).find("input.edit-revolution_slider-fields-data-y").val();
            $i = $current++;
            $slideWrap = e(".slide-builder").find("div.preview-bg");
            $selected = e(this).find("select.edit-revolution_slider-fields-layer");
            $img = e(this).find(".form-managed-file span.file").find("a").attr("href");
            $h1 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $h2 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $h3 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $h4 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $h5 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $h6 = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $div = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
            $css = e(this).find("input.edit-revolution_slider-fields-css-" + $i).val();
            $cssField = e(this).find(".edit-revolution_slider-fields-css-" + $i);
            e(this).find("input.edit-revolution_slider-fields-data-x").addClass("layer-x-" + $i + "-draggable");
            e(this).find("input.edit-revolution_slider-fields-data-y").addClass("layer-y-" + $i + "-draggable");
            e(this).find("select.edit-revolution_slider-fields-layer").addClass("select-" + $i + "-menu");

            
            $slideWrap.append('<div class="layer layer-' + $i + '-editor" style="left: '+t+'px; top: ' + $y + 'px"></div>');
            
            switch ($selected.val()) {
	            case "img":
	                if ($img == undefined) {
	                    e(".layer-" + $i + "-editor").html("New Image")
	                } else {
	                    e(".layer-" + $i + "-editor").html('<img class="' + $css + '" src="' + $img + '" />')
	                }
	            break;
	            case "h1": e(".layer-" + $i + "-editor").html('<h1 class="tp-caption ' + $css + '">' + $div.val() + "</h1>"); break;
	            case "h2": e(".layer-" + $i + "-editor").html('<h2 class="tp-caption ' + $css + '">' + $div.val() + "</h2>"); break;
	            case "h3": e(".layer-" + $i + "-editor").html('<h3 class="tp-caption ' + $css + '">' + $div.val() + "</h3>"); break;
	            case "h4": e(".layer-" + $i + "-editor").html('<h4 class="tp-caption ' + $css + '">' + $div.val() + "</h4>"); break;
	            case "h5": e(".layer-" + $i + "-editor").html('<h5 class="tp-caption ' + $css + '">' + $div.val() + "</h6>"); break;
	            case "h6": e(".layer-" + $i + "-editor").html('<h6 class="tp-caption ' + $css + '">' + $div.val() + "</h1>"); break;
	            case "div": e(".layer-" + $i + "-editor").html('<div class="tp-caption ' + $css + '">' + $div.val() + "</div>"); break;
	            default: e(".layer-" + $i + "-editor").html("New Layer"); break; 
            }
            
            var n = e(this).index();
            e(".select-" + n + "-menu").change(function () {
                $img = e(this).parents().eq(2).find(".form-managed-file span.file").find("a").attr("href");
                $h1 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $h2 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $h3 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $h4 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $h5 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $h6 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $div = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + n);
                $css = 'tp-caption '+e(this).parents().eq(3).find("input.edit-revolution_slider-fields-css-" + n).val();
                switch (e(this).val()) {
                case "img":
                    if ($img == undefined) {
                        e(".layer-" + n + "-editor").html("New Image")
                    } else {
                        e(".layer-" + n + "-editor").html('<img class="' + $css + '" src="' + $img + '" />')
                    }
                    break;
                case "h1":
                    e(".layer-" + n + "-editor").html('<h1 class="' + $css + '">' + $div.val() + "</h1>");
                    break;
                case "h2":
                    e(".layer-" + n + "-editor").html('<h2 class="' + $css + '">' + $div.val() + "</h2>");
                    break;
                case "h3":
                    e(".layer-" + n + "-editor").html('<h3 class="' + $css + '">' + $div.val() + "</h3>");
                    break;
                case "h4":
                    e(".layer-" + n + "-editor").html('<h4 class="' + $css + '">' + $div.val() + "</h4>");
                    break;
                case "h5":
                    e(".layer-" + n + "-editor").html('<h5 class="' + $css + '">' + $div.val() + "</h6>");
                    break;
                case "h6":
                    e(".layer-" + n + "-editor").html('<h6 class="' + $css + '">' + $div.val() + "</h1>");
                    break;
                case "div":
                    e(".layer-" + n + "-editor").html('<div class="' + $css + '">' + $div.val() + "</div>");
                    break;
                default:
                    e(".layer-" + n + "-editor").html("New Layer");
                    break
                }
            });
            e(".layer-" + n + "-editor").draggable({
                cursor: "crosshair",
                containment: "parent",
                stop: function (t, r) {
                    var i = $slideWrap.offset();
                    $pos = r.helper.offset();
                    e(".layer-x-" + n + "-draggable").val(($pos.left - i.left).toFixed(0));
                    e(".layer-y-" + n + "-draggable").val(($pos.top - i.top).toFixed(0))
                }
            });
            e("input.layer-x-" + n + "-draggable").keyup(function () {
                e(".layer-" + n + "-editor").css("left", e(this).val() + "px")
            });
            e("input.layer-y-" + n + "-draggable").keyup(function () {
                e(".layer-" + n + "-editor").css("top", e(this).val() + "px")
            });
            $cssField.keyup(function (t) {
                $value = 'tp-caption '+e(this).val();
                t = $value;
                switch (e(".select-" + n + "-menu").val()) {
                case "img":
                    e(".layer-" + n + "-editor > img").removeClass().addClass($value);
                    break;
                case "h1":
                    e(".layer-" + n + "-editor > h1").removeClass().addClass($value);
                    break;
                case "h2":
                    e(".layer-" + n + "-editor > h2").removeClass().addClass($value);
                    break;
                case "h3":
                    e(".layer-" + n + "-editor > h3").removeClass().addClass($value);
                    break;
                case "h4":
                    e(".layer-" + n + "-editor > h4").removeClass().addClass($value);
                    break;
                case "h5":
                    e(".layer-" + n + "-editor > h5").removeClass().addClass($value);
                    break;
                case "h6":
                    e(".layer-" + n + "-editor > h6").removeClass().addClass($value);
                    break;
                case "div":
                    e(".layer-" + n + "-editor > div").removeClass().addClass($value);
                    break
                }
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h1").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h2").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h3").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h4").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h5").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > h6").text(e(this).val())
            });
            $div.keyup(function () {
                e(".layer-" + n + "-editor > div").text(e(this).val())
            })
        });
        Drupal.behaviors.revolution_slider = {
            attach: function (t, n) {
                $last.show();
                $last = e(".field-type-revolution-slider-layer table.field-multiple-table tr.draggable:last");
                $subLayer = e(".field-type-revolution-slider-layer table.field-multiple-table tr.draggable:not(:last)");
                $index = $last.index() - 1;
                $last.hide();
                e("input.field-add-more-submit", t).once("revolution_slider", function () {
                    $subLayer.each(function () {
                        $i = e(this).index();
                        e(this).find("input.edit-revolution_slider-fields-data-x").addClass("layer-x-" + $i + "-draggable");
                        e(this).find("input.edit-revolution_slider-fields-data-y").addClass("layer-y-" + $i + "-draggable");
                        e(this).find("select.edit-revolution_slider-fields-layer").addClass("select-" + $i + "-menu");
                        $slideWrap = e(".slide-builder").find("div.preview-bg");
                        $div = e(this).find(".edit-revolution_slider-fields-markup-" + $i);
                        $css = e(this).find("input.edit-revolution_slider-fields-css-" + $i).val();
                        $cssField = e(this).find(".edit-revolution_slider-fields-css-" + $i);
                        
                        var t = e(this).index();
                        
                        e(".select-" + t + "-menu").change(function () {
                            $img = e(this).parents().eq(2).find(".form-managed-file span.file").find("a").attr("href");
                            $h1 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h1-" + t);
                            $h2 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h2-" + t);
                            $h3 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h3-" + t);
                            $h4 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h4-" + t);
                            $h5 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h5-" + t);
                            $h6 = e(this).parents().eq(3).find(".edit-revolution_slider-fields-h6-" + t);
                            $div = e(this).parents().eq(3).find(".edit-revolution_slider-fields-markup-" + t);
                            $css = 'tp-caption '+e(this).parents().eq(3).find("input.edit-revolution_slider-fields-css-" + t).val();
                            switch (e(this).val()) {
                            case "img":
                                if ($img == undefined) {
                                    e(".layer-" + t + "-editor").html("New Image")
                                } else {
                                    e(".layer-" + t + "-editor").html('<img class="' + $css + '" src="' + $img + '" />')
                                }
                                break;
                            case "h1":
                                e(".layer-" + t + "-editor").html('<h1 class="' + $css + '">' + $div.val() + "</h1>");
                                break;
                            case "h2":
                                e(".layer-" + t + "-editor").html('<h2 class="' + $css + '">' + $div.val() + "</h2>");
                                break;
                            case "h3":
                                e(".layer-" + t + "-editor").html('<h3 class="' + $css + '">' + $div.val() + "</h3>");
                                break;
                            case "h4":
                                e(".layer-" + t + "-editor").html('<h4 class="' + $css + '">' + $div.val() + "</h4>");
                                break;
                            case "h5":
                                e(".layer-" + t + "-editor").html('<h5 class="' + $css + '">' + $div.val() + "</h6>");
                                break;
                            case "h6":
                                e(".layer-" + t + "-editor").html('<h6 class="' + $css + '">' + $div.val() + "</h1>");
                                break;
                            case "div":
                                e(".layer-" + t + "-editor").html('<div class="' + $css + '">' + $div.val() + "</div>");
                                break;
                            default:
                                e(".layer-" + t + "-editor").html("New Layer");
                                break;
                            }
                        });
                        e(".layer-" + t + "-editor").draggable({
                            cursor: "crosshair",
                            containment: "parent",
                            stop: function (n, r) {
                                var i = $slideWrap.offset();
                                $pos = r.helper.offset();
                                e(".layer-x-" + t + "-draggable").val(($pos.left - i.left).toFixed(0));
                                e(".layer-y-" + t + "-draggable").val(($pos.top - i.top).toFixed(0))
                            }
                        });
                        e("input.layer-x-" + t + "-draggable").keyup(function () {
                            e(".layer-" + t + "-editor").css("left", e(this).val() + "px")
                        });
                        e("input.layer-y-" + t + "-draggable").keyup(function () {
                            e(".layer-" + t + "-editor").css("top", e(this).val() + "px")
                        });
                        $cssField.keyup(function (n) {
                            $value = 'tp-caption '+e(this).val();
                            n = $value;
                            switch (e(".select-" + t + "-menu").val()) {
                            case "img":
                                e(".layer-" + t + "-editor > img").removeClass().addClass($value);
                                break;
                            case "h1":
                                e(".layer-" + t + "-editor > h1").removeClass().addClass($value);
                                break;
                            case "h2":
                                e(".layer-" + t + "-editor > h2").removeClass().addClass($value);
                                break;
                            case "h3":
                                e(".layer-" + t + "-editor > h3").removeClass().addClass($value);
                                break;
                            case "h4":
                                e(".layer-" + t + "-editor > h4").removeClass().addClass($value);
                                break;
                            case "h5":
                                e(".layer-" + t + "-editor > h5").removeClass().addClass($value);
                                break;
                            case "h6":
                                e(".layer-" + t + "-editor > h6").removeClass().addClass($value);
                                break;
                            case "div":
                                e(".layer-" + t + "-editor > div").removeClass().addClass($value);
                                break;
                            }
                        });
                        
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h1").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h2").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h3").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h4").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h5").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > h6").text(e(this).val())
                        });
                        $div.keyup(function () {
                            e(".layer-" + t + "-editor > div").text(e(this).val())
                        })
                    });
                    $newLayer = e("div.preview-bg > .layer-" + $index + "-editor").exists();
                    if ($newLayer == false) {
                        $slideWrap.append('<div class="layer layer-' + $index + '-editor">New Layer</div>')
                    }
                    e(".preview-bg > div.layer").each(function () {
                        e(".layer-" + $index + "-editor").draggable({
                            cursor: "crosshair",
                            containment: "parent",
                            stop: function (t, n) {
                                var r = $slideWrap.offset();
                                $pos = n.helper.offset();
                                e(".layer-x-" + $index + "-draggable").val(($pos.left - r.left).toFixed(0));
                                e(".layer-y-" + $index + "-draggable").val(($pos.top - r.top).toFixed(0))
                            }
                        })
                    })
                });
                $preview_img = e("#edit-field-image .image-widget span.file").find("a").attr("href");
                e("#edit-field-image .image-widget input[type='submit']").once(function () {
                    var t = new Image;
                    t.onload = function () {
                        e(".slide-builder").width(e(".slide-builder").parent().width());
                        e("div.preview-bg").css("width", $width).css("height", $height).css("background-position", "center");
                    };
                    t.src = $preview_img;
                    if ($preview_img == undefined) {
                        e("div.preview-bg").css("background-image", "none")
                    } else {
                        e("div.preview-bg").css("background-image", "url(" + $preview_img + ")")
                    }
                });
                $subLayer.each(function () {
                    $i = e(this).index();
                    $img = e(this).find(".form-managed-file span.file").find("a").attr("href");
                    $selected = e(this).find("select.edit-revolution_slider-fields-layer");
                    e(".edit-revolution_slider-fields-image-" + $i + " > input[type='submit'], .edit-revolution_slider-fields-image-" + $i + " > input[type='submit']").once(function () {
                        if ($img == undefined && $selected.val() == "img") {
                            e(".layer-" + $i + "-editor").html("New Image")
                        } else if ($img !== undefined && $selected.val() == "img") {
                            e(".layer-" + $i + "-editor").html('<img src="' + $img + '" />')
                        }
                    })
                })
            }
        }
    }
})
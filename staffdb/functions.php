<?php

function get_remote_list($q) {
  db_set_active('remote');
  $result = db_query($q);
  db_set_active();
  $ids = array();
  foreach ($result as $row) {
    $ids[$row->name] = $row->id;
  }
  return $ids;
}

function makeDirectory($dirArray, $sort = NULL) {

  /*
  print "<pre>";
  print_r($dirArray);
  print "</pre>";
  */
  // Table opening code
  $dir_code = "<table cellpadding=\"10\" cellspacing=\"5\" id=\"stafflist\" summary=\"Staff directory\" class=\"filterable stripey\">\n";
  $dir_code .= "<thead>\n";
  $dir_code .= "<tr>\n";
  if (!isset($sort) || $sort == "") {
    $img_code = "^";
  }
  else {
    $img_code = "";
  }
  $dir_code .= "<th scope=\"col\"><a href=\"index-db.php\">Name</a>{$img_code}</th>\n";
  $dir_code .= "<th scope=\"col\">Title/Rank</th>\n";
  if (isset($sort) && $sort == "dept, ") {
    $img_code = "^";
  }
  else {
    $img_code = "";
  }
  $dir_code .= "<th scope=\"col\"><a href=\"index-db.php?sort=dept\">Department</a>{$img_code}</th>\n";
  if (isset($sort) && $sort == "loc, ") {
    $img_code = "^";
  }
  else {
    $img_code = "";
  }
  $dir_code .= "<th scope=\"col\"><a href=\"index-db.php?sort=loc\">Location</a>{$img_code}</th>\n";
  if (isset($sort) && $sort == "sub, ") {
    $img_code = "^";
  }
  else {
    $img_code = "";
  }
  $dir_code .= "<th scope=\"col\"><a href=\"index-db.php?sort=sub\">Subjects</a>{$img_code}</th>\n";
  $dir_code .= "</tr>\n";
  $dir_code .= "</thead>\n";
  $dir_code .= "<tbody>\n";
  // Generate rows
  $letter = "";
  $last_letter = "";
  $cur_id = "";
  $last_id = "";
  foreach ($dirArray as $key => $empval) {
    if (isset($sort) && $sort == "dept, ") { // Set sort option
      unset($rowArray);
      $rowArray = array();
      if (isset($empval["dept"]) && $empval["dept"] != "") {
        foreach ($empval["dept"] as $deptkey => $deptval) {
          // Empty or set variables
          $telArray = "";
          $tel_code = "";
          $roomArray = "";
          $room_code = "";
          $deptArray = "";
          $dept_code = "";
          $subArray = "";
          $sub_code = "";
          if (isset($deptval) && $deptval != "") {
            $letter = $deptval;
            if (!array_key_exists($letter, $rowArray)) {
              $divide_code = "<tr id=\"listby\">\n";
              $divide_code .= "<td colspan=\"4\"><a name=\"$letter\"></a>$letter</td>\n";
              $divide_code .= "<td id=\"backtotop\">Back to top</td>\n";
              $divide_code .= "</tr>\n";
              $rowArray["$letter"] = "{$divide_code}";
            }
            // Make row content
            $sort_val = "{$deptval} {$empval["last_name"]} {$empval["first_name"]} {$empval["middle_name"]}";
            if (!array_key_exists($sort_val, $rowArray)) {
              $dept_code = "{$deptval}";
              // Build loc/phone content, as they are together in the db and must be separated for display
              if (!empty($empval["box_id"])) {
                $locArray = "";
                foreach ($empval["box_id"] as $boxkey => $boxval) {
                  if (isset($boxval["telephone"]) && $boxval["telephone"] != "") {
                    $telArray[] = $boxval["telephone"];
                  }
                  if (isset($boxval["room"]) && $boxval["room"] != "") {
                    $roomArray[] = $boxval["room"];
                  }
                  if (isset($boxval["loc"]) && $boxval["loc"] != "") {
                    $locArray[] = $boxval["loc"];
                  }
                  if (isset($locArray)) {
                    $locArrayFinal = "";
                    for ($i = 0; $i < count($locArray); $i++) {
                      if (isset($roomArray[$i]) && $roomArray[$i] != "") {
                        $room_info = "{$roomArray[$i]}";
                      }
                      else {
                        $room_info = "";
                      }
                      $locArrayFinal[$i] = "{$locArray[$i]} {$room_info}";
                    }
                  }
                }
              }
              if (!empty($telArray)) {
                $tel_code = "(505) " . implode("<br />(505) ", array_unique($telArray));
              }
              else {
                $tel_code = "";
              }
              if (!empty($locArrayFinal)) {
                sort($locArrayFinal);
                $room_code = implode("<br />", array_unique($locArrayFinal));
              }
              else {
                $room_code = "";
              }
              // Build rank content
              if (!empty($empval["rank"])) {
                $rank_code = $empval["rank"];
              }
              else {
                $rank_code = "";
              }
              // Build title content
              if (!empty($empval["title"])) {
                $title_code = $empval["title"] . "<br />";
              }
              else {
                $title_code = "";
              }
              // Build subject content
              if (!empty($empval["subjects"])) {
                foreach ($empval["subjects"] as $key => $val) {
                  $subArray[] = $val;
                }
              }
              if (!empty($subArray)) {
                sort($subArray);
                $sub_code = implode("<br />", array_unique($subArray));
              }
              else {
                $sub_code = "";
              }
              // Build content rows
              $name_col = "";
              $rank_col = "";
              $dept_col = "";
              $loc_col = "";
              $sub_col = "";
              if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
                $name_col .= "<a href=\"{$empval["rg_profile"]}\">";
              }
              $name_col .= "{$empval["first_name"]} {$empval["middle_name"]} {$empval["last_name"]}";
              if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
                $name_col .= "</a>";
              }
              $name_col .= "<br /><a href=\"mailto:{$empval["email"]}\">{$empval["email"]}</a><br />{$tel_code}";
              $rank_col .= "{$title_code}{$rank_code}";
              $dept_col .= "{$dept_code}";
              $loc_col .= "{$room_code}";
              $sub_col .= "$sub_code";
              // Add whole row to $rowArray with sub (or first letter of sub) as sort key
              if (!isset($rowArray["$sort_val"]) || $rowArray["$sort_val"] == "") {
                $rowArray["$sort_val"] = array(
                  $name_col,
                  $rank_col,
                  $dept_col,
                  $loc_col,
                  $sub_col
                );
              }
              else {
                $rowArray["$sort_val"][0] .= "<br />{$name_col}";
                $rowArray["$sort_val"][1] .= "<br />{$rank_col}";
                $rowArray["$sort_val"][2] .= "<br />{$dept_col}";
                $rowArray["$sort_val"][3] .= "<br />{$loc_col}";
                $rowArray["$sort_val"][4] .= "<br />{$sub_col}";
              }


            }
          } //  END if (isset($deptval) && $deptval != ""), line 81

        }
      }
      foreach ($rowArray as $key => $val) {
        if (is_array($val) && !empty($val)) {
          $bySubArray[$key] = "<tr>\n<td>" . implode("</td>\n<td>", $val) . "</td>\n</tr>\n";
        }
        elseif (is_string($val) && !empty($val)) {
          $bySubArray[$key] = "{$val}";
        }
      }


    }
    elseif (isset($sort) && $sort == "loc, ") {
      unset($rowArray);
      $rowArray = array();
      if (isset($empval["box_id"]) && $empval["box_id"] != "") {
        foreach ($empval["box_id"] as $boxkey => $boxval) {
          // Empty or set variables
          $telArray = "";
          $tel_code = "";
          $roomArray = "";
          $room_code = "";
          $deptArray = "";
          $dept_code = "";
          $subArray = "";
          $sub_code = "";
          if (isset($boxval["loc"]) && $boxval["loc"] != "") {
            $letter = strtoupper(substr($boxval["loc"], 0, 1));
            if (!array_key_exists($letter, $rowArray)) {
              $divide_code = "<tr id=\"listby\">\n";
              $divide_code .= "<td colspan=\"4\"><a name=\"$letter\"></a>{$boxval["loc"]}</td>\n";
              $divide_code .= "<td id=\"backtotop\">Back to top</td>\n";
              $divide_code .= "</tr>\n";
              $rowArray["$letter"] = "{$divide_code}";
            }
          }
          if (isset($boxval["loc"]) && $boxval["loc"] != "") {
            $room_code = $boxval["loc"];
          }
          if (isset($boxval["room"]) && $boxval["room"] != "") {
            if (isset($room_code)) {
              $room_code .= " " . $boxval["room"];
            }
            else {
              $room_code = "";
            }
          }
          if (isset($boxval["telephone"]) && $boxval["telephone"] != "") {
            $telArray[] = $boxval["telephone"];
          }
          if (!empty($telArray)) {
            $tel_code = "(505) " . implode("<br />(505) ", array_unique($telArray));
          }
          else {
            $tel_code = "";
          }
          // Build rank content
          if (!empty($empval["rank"])) {
            $rank_code = $empval["rank"];
          }
          else {
            $rank_code = "";
          }
          // Build title content
          if (!empty($empval["title"])) {
            $title_code = $empval["title"] . "<br />";
          }
          else {
            $title_code = "";
          }
          // Build dept content
          if (!empty($empval["dept"])) {
            foreach ($empval["dept"] as $key => $val) {
              $deptArray[] = $val;
            }
          }
          if (!empty($deptArray)) {
            ksort($deptArray);
            $dept_code = implode("<br />", array_unique($deptArray));
          }
          else {
            $dept_code = "";
          }
          // Build subject content
          if (!empty($empval["subjects"])) {
            foreach ($empval["subjects"] as $key => $val) {
              $subArray[] = $val;
            }
          }
          if (!empty($subArray)) {
            sort($subArray);
            $sub_code = implode("<br />", array_unique($subArray));
          }
          else {
            $sub_code = "";
          }
          // Build content rows
          $name_col = "";
          $rank_col = "";
          $dept_col = "";
          $loc_col = "";
          $sub_col = "";
          if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
            $name_col .= "<a href=\"{$empval["rg_profile"]}\">";
          }
          $name_col .= "{$empval["first_name"]} {$empval["middle_name"]} {$empval["last_name"]}";
          if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
            $name_col .= "</a>";
          }
          $sort_val = "$letter {$empval["last_name"]} {$empval["first_name"]} {$empval["middle_name"]}";
          $name_col .= "<br /><a href=\"mailto:{$empval["email"]}\">{$empval["email"]}</a><br />{$tel_code}";
          $rank_col .= "{$title_code}{$rank_code}";
          $dept_col .= "{$dept_code}";
          $loc_col .= "{$room_code}";
          $sub_col .= "$sub_code";

          // Add whole row to $rowArray with 'loc last_name first_name middle_name' (or first letter of loc) as sort key
          if (!isset($rowArray["$sort_val"]) || $rowArray["$sort_val"] == "") {
            $rowArray["$sort_val"] = array(
              $name_col,
              $rank_col,
              $dept_col,
              $loc_col,
              $sub_col
            );
          }
          else {
            $rowArray["$sort_val"][0] .= "<br />{$name_col}";
            $rowArray["$sort_val"][1] .= "<br />{$rank_col}";
            $rowArray["$sort_val"][2] .= "<br />{$dept_col}";
            $rowArray["$sort_val"][3] .= "<br />{$loc_col}";
            $rowArray["$sort_val"][4] .= "<br />{$sub_col}";
          }
        } // END foreach ($empval["box_id"] as $boxkey => $boxval), line 70
      }
      foreach ($rowArray as $key => $val) {
        if (is_array($val) && !empty($val)) {
          $bySubArray[$key] = "<tr>\n<td>" . implode("</td>\n<td>", $val) . "</td>\n</tr>\n";
        }
        elseif (is_string($val) && !empty($val)) {
          $bySubArray[$key] = "{$val}";
        }
      }
    }
    elseif (isset($sort) && $sort == "sub, ") {
      unset($rowArray);
      $rowArray = array();
      // Build subject content
      // $subArray => array(sort value, content); sort value = subject or first letter of subject (divider lines)
      if (!empty($empval["subjects"])) {
        foreach ($empval["subjects"] as $subkey => $subval) {
          // Empty or set variables
          $deptArray = "";
          $dept_code = "";
          $locArray = "";
          $loc_code = "";
          $roomArray = "";
          $room_code = "";
          $subArray = "";
          $sub_code = "";
          $telArray = "";
          $tel_code = "";
          $letter = strtoupper(substr($subval, 0, 1));
          if (!array_key_exists($letter, $rowArray)) {
            $divide_code = "<tr id=\"listby\">\n";
            $divide_code .= "<td colspan=\"4\"><a name=\"$letter\"></a>$letter</td>\n";
            $divide_code .= "<td id=\"backtotop\">Back to top</td>\n";
            $divide_code .= "</tr>\n";
            $rowArray["$letter"] = "{$divide_code}";
          }
          // Make row content
          if (!array_key_exists($subval, $rowArray)) {
            // Build loc/phone content, as they are together in the db and must be separated for display
            if (!empty($empval["box_id"])) {
              foreach ($empval["box_id"] as $boxkey => $boxval) {
                if (isset($boxval["telephone"]) && $boxval["telephone"] != "") {
                  $telArray[] = $boxval["telephone"];
                }
                if (isset($boxval["room"]) && $boxval["room"] != "") {
                  $roomArray[] = $boxval["room"];
                }
              }
            }
            if (!empty($telArray)) {
              $tel_code = "(505) " . implode("<br />(505) ", array_unique($telArray));
            }
            else {
              $tel_code = "";
            }
            if (isset($boxval["loc"]) && $boxval["loc"] != "") {
              $locArray[] = $boxval["loc"];
            }
            if (isset($locArray)) {
              $locArrayFinal = "";
              for ($i = 0; $i < count($locArray); $i++) {
                if (isset($roomArray[$i]) && $roomArray[$i] != "") {
                  $room_info = "{$roomArray[$i]}";
                }
                else {
                  $room_info = "";
                }
                $locArrayFinal[$i] = "{$locArray[$i]} {$room_info}";
              }
            }
            if (!empty($locArrayFinal)) {
              sort($locArrayFinal);
              $room_code = implode("<br />", array_unique($locArrayFinal));
            }
            else {
              $room_code = "";
            }
            // Build rank content
            if (!empty($empval["rank"])) {
              $rank_code = $empval["rank"];
            }
            else {
              $rank_code = "";
            }
            // Build title content
            if (!empty($empval["title"])) {
              $title_code = $empval["title"] . "<br />";
            }
            else {
              $title_code = "";
            }
            // Build dept content
            if (!empty($empval["dept"])) {
              foreach ($empval["dept"] as $key => $val) {
                $deptArray[] = $val;
              }
            }
            if (!empty($deptArray)) {
              ksort($deptArray);
              $dept_code = implode("<br />", array_unique($deptArray));
            }
            else {
              $dept_code = "";
            }
            $sub_code = "{$subval}";
            // Build content rows
            $name_col = "";
            $rank_col = "";
            $dept_col = "";
            $loc_col = "";
            $sub_col = "";
            if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
              $name_col .= "<a href=\"{$empval["rg_profile"]}\">";
            }
            $name_col .= "{$empval["first_name"]} {$empval["middle_name"]} {$empval["last_name"]}";
            if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
              $name_col .= "</a>";
            }
            $name_col .= "<br /><a href=\"mailto:{$empval["email"]}\">{$empval["email"]}</a><br />{$tel_code}";
            $rank_col .= "{$title_code}{$rank_code}";
            $dept_col .= "{$dept_code}";
            $loc_col .= "{$room_code}";
            $sub_col .= "$sub_code";

            // Add whole row to $rowArray with sub (or first letter of sub) as sort key
            if (!isset($rowArray["$subval"]) || $rowArray["$subval"] == "") {
              $rowArray["$subval"] = array(
                $name_col,
                $rank_col,
                $dept_col,
                $loc_col,
                $sub_col
              );
            }
            else {
              $rowArray["$subval"][0] .= "<br />{$name_col}";
              $rowArray["$subval"][1] .= "<br />{$rank_col}";
              $rowArray["$subval"][2] .= "<br />{$dept_col}";
              $rowArray["$subval"][3] .= "<br />{$loc_col}";
              $rowArray["$subval"][4] .= "<br />{$sub_col}";
            }
          }
        }
      }
      foreach ($rowArray as $key => $val) {
        if (is_array($val) && !empty($val)) {
          $bySubArray[$key] = "<tr>\n<td>" . implode("</td>\n<td>", $val) . "</td>\n</tr>\n";
        }
        elseif (is_string($val) && !empty($val)) {
          $bySubArray[$key] = "{$val}";
        }
      }
    }
    else { // No sort specified, default is name
      $letter = strtoupper(substr($empval["last_name"], 0, 1));
      $cur_id = "{$key}";
      if ($cur_id != $last_id) {
        $deptArray = "";
        $dept_code = "";
        $locArray = "";
        $locArrayFinal = "";
        $roomArray = "";
        $room_code = "";
        $subArray = "";
        $sub_code = "";
        $researchArray = "";
        $research_code = "";
        $classesArray = "";
        $classes_code = "";
        $telArray = "";
        $tel_code = "";
      }
      // Build header row if letter has changed
      if ($letter != $last_letter) {
        $dir_code .= "<tr id=\"listby\">\n";
        $dir_code .= "<td colspan=\"4\"><a name=\"$letter\"></a>$letter</td>\n";
        $dir_code .= "<td id=\"backtotop\">Back to top</td>\n";
        $dir_code .= "</tr>\n";
      }
      // Build loc/phone content, as they are together in the db and must be separated for display
      if (!empty($empval["box_id"])) {
        foreach ($empval["box_id"] as $boxkey => $boxval) {
          if (isset($boxval["telephone"]) && $boxval["telephone"] != "") {
            $telArray[] = $boxval["telephone"];
          }
          if (isset($boxval["room"]) && $boxval["room"] != "") {
            $roomArray[] = $boxval["room"];
          }
          if (isset($boxval["loc"]) && $boxval["loc"] != "") {
            $locArray[] = $boxval["loc"];
          }
          if (isset($locArray)) {
            $locArrayFinal = "";
            for ($i = 0; $i < count($locArray); $i++) {
              if (isset($roomArray[$i]) && $roomArray[$i] != "") {
                $room_info = "{$roomArray[$i]}";
              }
              else {
                $room_info = "";
              }
              $locArrayFinal[$i] = "{$locArray[$i]} {$room_info}";
            }
          }
        }
      }
      if (!empty($locArrayFinal)) {
        sort($locArrayFinal);
        $room_code = implode("<br />", array_unique($locArrayFinal));
      }
      else {
        $room_code = "";
      }
      if (!empty($telArray)) {
        $tel_code = "(505) " . implode("<br />(505) ", array_unique($telArray));
      }
      else {
        $tel_code = "";
      }
      // Build rank content
      if (!empty($empval["rank"])) {
        $rank_code = $empval["rank"];
      }
      else {
        $rank_code = "";
      }
      // Build title content
      if (!empty($empval["title"])) {
        $title_code = $empval["title"] . "<br />";
      }
      else {
        $title_code = "";
      }
      // Build dept content
      if (!empty($empval["dept"])) {
        foreach ($empval["dept"] as $key => $val) {
          $deptArray[] = $val;
        }
      }
      if (!empty($deptArray)) {
        ksort($deptArray);
        $dept_code = implode("<br />", array_unique($deptArray));
      }
      else {
        $dept_code = "";
      }
      // Build subject content
      if (!empty($empval["subjects"])) {
        foreach ($empval["subjects"] as $key => $val) {
          $subArray[] = $val;
        }
      }
      if (!empty($subArray)) {
        sort($subArray);
        $sub_code = implode("<br />", array_unique($subArray));
      }
      else {
        $sub_code = "";
      }
      // Build research content
      if (!empty($empval["research"])) {
        foreach ($empval["research"] as $key => $val) {
          $researchArray[] = $val;
        }
      }
      if (!empty($researchArray)) {
        sort($researchArray);
        $research_code = implode("<br />", array_unique($researchArray));
      }
      else {
        $research_code = "";
      }
      // Build classes content
      if (!empty($empval["classes"])) {
        foreach ($empval["classes"] as $key => $val) {
          $classesArray[] = $val;
        }
      }
      if (!empty($classesArray)) {
        sort($classesArray);
        $classes_code = implode("<br />", array_unique($classesArray));
      }
      else {
        $classes_code = "";
      }
      // Build content rows
      $dir_code .= "<tr>\n";
      $dir_code .= "<td>";
      $name_code = "";
      if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
        $dir_code .= "<a href=\"{$empval["rg_profile"]}\">";
        $name_code .= "<a href=\"{$empval["rg_profile"]}\">";
      }
      $dir_code .= "{$empval["first_name"]} {$empval["middle_name"]} {$empval["last_name"]}";
      $name_code .= "{$empval["first_name"]} {$empval["middle_name"]} {$empval["last_name"]}";
      if (isset($empval["rg_profile"]) && $empval["rg_profile"] != "") {
        $dir_code .= "</a>";
        $name_code .= "</a>";
      }
      $dir_code .= "<br /><a href=\"mailto:{$empval["email"]}\">{$empval["email"]}</a><br />{$tel_code}</td>\n";
      $name_code .= "<br /><a href=\"mailto:{$empval["email"]}\">{$empval["email"]}</a><br />{$tel_code}";
      $dir_code .= "<td>{$title_code}{$rank_code}</td>\n";
      $dir_code .= "<td>{$dept_code}</td>\n";
      $dir_code .= "<td>{$room_code}</td>\n";
      $dir_code .= "<td>$sub_code</td>\n";
      $dir_code .= "</tr>\n";
      $dir_code .= "\n";
      $last_letter = $letter;
      $last_id = $cur_id;
      //   $ret_array[] = array("$name_code", "$title_code$rank_code", "$dept_code", "$room_code", "$sub_code");
      $ret_array[] = array(
        "name" => "$name_code",
        "title" => "$title_code$rank_code",
        "dept" => "$dept_code",
        "room" => "$room_code",
        "id" => "$cur_id",
        "research" => "$research_code",
        "classes" => "$classes_code"
      );
    }
  }
  return $ret_array;
  // Subject array, all rows gathered; now surround in table row code and add
  if (isset($bySubArray) && $bySubArray != "") {
    ksort($bySubArray);
    foreach ($bySubArray as $key => $val) {
      if (is_array($val) && !empty($val)) {
        $dir_code .= "<tr>\n<td>" . implode("</td>\n<td>", $val) . "</td>\n</tr>\n";
      }
      elseif (is_string($val) && !empty($val)) {
        $dir_code .= "{$val}";
      }
    }
  }

  // Table closing code
  $dir_code .= "</tbody>\n";
  $dir_code .= "</table>\n";
  $dir_code = utf8_encode($dir_code);
  //   return $dir_code;
}

function massage_employee_data($resultset, $options = NULL) {
  foreach ($resultset as $val) {
    if (empty($varArray[$val->id]["dept"])) {
      $varArray[$val->id] = array(
        "dept" => array(),
        "box_id" => array(),
        "subjects" => array(),
        "website" => array()
      );
    }
    if (isset($val->id) && $val->id != "") {
      $varArray[$val->id]["id"] = $val->id;
    }
    if (isset($val->first_name) && $val->first_name != "") {
      $varArray[$val->id]["first_name"] = $val->first_name;
    }
    if (isset($val->middle_name) && $val->middle_name != "") {
      $varArray[$val->id]["middle_name"] = $val->middle_name;
    }
    else {
      $varArray[$val->id]["middle_name"] = "";
    }
    if (isset($val->last_name) && $val->last_name != "") {
      $varArray[$val->id]["last_name"] = $val->last_name;
    }
    if (isset($val->visible) && $val->visible != "") {
      $varArray[$val->id]["visible"] = $val->visible;
    }
    if (isset($val->email) && $val->email != "") {
      $varArray[$val->id]["email"] = $val->email;
    }
    if (isset($val->rg_profile) && $val->rg_profile != "") {
      $varArray[$val->id]["rg_profile"] = $val->rg_profile;
    }
    if (isset($val->blurb) && $val->blurb != "") {
      $varArray[$val->id]["blurb"] = $val->blurb;
    }
    if (isset($val->picture) && $val->picture != "") {
      $varArray[$val->id]["picture"] = $val->picture;
    }
    if (isset($val->rank) && $val->rank != "") {
      $varArray[$val->id]["rank"] = $val->rank;
    }
    if (isset($val->title) && $val->title != "") {
      $varArray[$val->id]["title"] = $val->title;
    }
    if (isset($val->dept) && $val->dept != "" && !in_array($val->dept, $varArray[$val->id]["dept"])) {
      $varArray[$val->id]["dept"][] = $val->dept;
    }
    if (isset($val->box_id) && $val->box_id != "") {
      if (!array_key_exists($val->box_id, $varArray[$val->id]["box_id"])) {
        $varArray[$val->id]["box_id"][$val->box_id] = array();
      }
      if (!isset($varArray["box_id"][$val->id][$val->box_id]["loc"])) {
        $varArray[$val->id]["box_id"][$val->box_id]["loc"] = $val->loc;
      }
      if (!isset($varArray[$val->id]["box_id"][$val->box_id]["room"])) {
        $varArray[$val->id]["box_id"][$val->box_id]["room"] = $val->room;
      }
      if (!isset($varArray[$val->id]["box_id"][$val->box_id]["telephone"])) {
        $varArray[$val->id]["box_id"][$val->box_id]["telephone"] = $val->telephone;
      }
    }
    if (isset($val->sub) && $val->sub != "") {
      $varArray[$val->id]["subjects"][] = $val->sub;
    }
    if (isset($val->classes) && $val->classes != "") {
      $varArray[$val->id]["classes"][] = $val->classes;
    }
    if (isset($val->research) && $val->research != "") {
      $varArray[$val->id]["research"][] = $val->research;
    }
    if (isset($val->website) && $val->website != "") {
      if (!in_array($val->website, $varArray[$val->id]["website"])) {
        $varArray[$val->id]["website"][] = $val->website;
      }
    }
    if (isset($val->current_teach) && is_numeric($val->current_teach) && $val->current_teach > -1 && $val->current_teach < 2) {
      $varArray[$val->id]["currently_teaching"] = $val->current_teach;
    }
    else {
      $varArray[$val->id]["currently_teaching"] = 0;
    }
    if (isset($val->ul_employee) && is_numeric($val->ul_employee) && $val->ul_employee > -1 && $val->ul_employee < 2) {
      $varArray[$val->id]["ul_employee"] = $val->ul_employee;
    }
    else {
      $varArray[$val->id]["ul_employee"] = 0;
    }
    if (isset($val->oils_employee) && is_numeric($val->oils_employee) && $val->oils_employee > -1 && $val->oils_employee < 2) {
      $varArray[$val->id]["oils_employee"] = $val->oils_employee;
    }
    else {
      $varArray[$val->id]["oils_employee"] = 0;
    }
    if (isset($val->codhead) && is_numeric($val->codhead) && $val->codhead > -1 && $val->codhead < 2) {
      $varArray[$val->id]["codhead"] = $val->codhead;
    }
    else {
      $varArray[$val->id]["codhead"] = 0;
    }
    if (isset($val->cv_link) && $val->cv_link != "") {
      $varArray[$val->id]["cv_link"] = $val->cv_link;
    }
  }
  return $varArray;
}
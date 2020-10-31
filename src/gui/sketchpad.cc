#include <gui/sketchpad.h>

namespace naivebayes {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      brush_radius_(brush_radius) {

  std::vector<int> empty_row;
  for(size_t row_index = 0; row_index < num_pixels_per_side_; row_index++){
    image_pixels_.push_back(empty_row);

    for(size_t column_index = 0; column_index < num_pixels_per_side_; column_index++){
      image_pixels_[row_index].push_back(0);
    }
  }
}

void Sketchpad::Draw() const {
  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {

      if (image_pixels_[row][col] == 1) {
        ci::gl::color(ci::Color::gray(0.3f));
      } else {
        ci::gl::color(ci::Color("white"));
      }

      vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                    row * pixel_side_length_);

      vec2 pixel_bottom_right =
          pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
      ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

      ci::gl::drawSolidRect(pixel_bounding_box);

      ci::gl::color(ci::Color("black"));
      ci::gl::drawStrokedRect(pixel_bounding_box);
    }
  }
}

void Sketchpad::HandleBrush(const vec2& brush_screen_coords) {
  vec2 brush_sketchpad_coords =
      (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

  size_t x_coord = static_cast<int>(brush_sketchpad_coords.x);
  size_t y_coord = static_cast<int>(brush_sketchpad_coords.y);

  bool x_coord_in_range = x_coord < num_pixels_per_side_ && x_coord > 0;
  bool y_coord_in_range = y_coord < num_pixels_per_side_ && y_coord > 0;

  if(x_coord_in_range && y_coord_in_range){
    if(image_pixels_[y_coord][x_coord] == 0){
      image_pixels_[y_coord][x_coord] = 1;
    }
  }
}

void Sketchpad::Clear() {
  for(size_t row_index = 0; row_index < image_pixels_.size(); row_index++){
    for(size_t column_index = 0; column_index < image_pixels_.size(); column_index++){
      image_pixels_[row_index][column_index] = 0;
    }
  }
}

const std::vector<std::vector<int>>& Sketchpad::GetImagePixels() const {
  return image_pixels_;
}

}  // namespace visualizer

}  // namespace naivebayes

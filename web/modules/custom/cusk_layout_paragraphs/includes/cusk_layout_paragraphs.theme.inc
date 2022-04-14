<?php

/**
 * @file
 * Theme hooks, preprocessor, and suggestions.
 */

 /**
 * Implements hook_theme().
 */
function cusk_layout_paragraphs_theme() {
  return [
    'paragraph__cusk_lp_content_anchor_link' => [
      'base hook' => 'paragraph',
    ],
  ];
}

/**
 * Implements template_preprocess_HOOK()
 */
function _paragraph__cusk_lp_content_anchor_link(&$variables) {
}

/**
 * Implements template_preprocess_HOOK()
 */
function _paragraph__cusk_lp_content_horizontal_rule(&$variables) {
  $paragraph = $variables['elements']['#paragraph'];
  $variables['border_color'] = $paragraph->hasField('field_cusk_lp_border_color') ? $paragraph->get('field_cusk_lp_border_color')->value : '';
  $variables['padding_tb'] = $paragraph->hasField('field_cusk_lp_padding_top_bottom') ? $paragraph->get('field_cusk_lp_padding_top_bottom')->value : '';
}

/**
 * Implements template_preprocess_HOOK()
 */
function _paragraph__cusk_lp_content_media(&$variables) {
  $paragraph = $variables['elements']['#paragraph'];
  $variables['is_figure'] = ($paragraph->hasField('field_cusk_lp_caption') && $paragraph->get('field_cusk_lp_caption')->value) ? true : false;
  $variables['caption_align'] = $paragraph->hasField('field_cusk_lp_caption_alignment') ? $paragraph->get('field_cusk_lp_caption_alignment')->value : '';
}

/**
 * Implements hook_theme_suggestions().
 * 
 * Used for development
 */
function _theme_suggestions_cusk_layout_paragraphs(array $variables) {
  $suggestions = [];
  $sanitized_view_mode = strtr($variables['elements']['#view_mode'], '.', '_');
  $suggestions[] = 'cusk_layout_paragraphs__' . $sanitized_view_mode;
  $suggestions[] = 'cusk_layout_paragraphs__' . $variables['elements']['field_name'];
  $suggestions[] = 'cusk_layout_paragraphs__' . $variables['elements']['field_name'] . '__' . $sanitized_view_mode;
  return $suggestions;
}

function _theme_suggestions_form_element_alter(array &$suggestions, array $variables) {
  $elementId = str_replace('-', '_', $variables['element']['#id']);
  $formId = str_replace('-', '_', $variables['element']['#form_id']);
  $suggestions[] = 'form_element__' . $formId . '__' . $elementId;
}